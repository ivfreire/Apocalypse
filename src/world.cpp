#include "world.h"

World::World(Controller* ctrl, std::string path) {
	srand(time(NULL));

	this->ctrl = ctrl;

	this->map = new Map(path);
	this->map->RenderLayers(ctrl->renderer);

	this->size = { (float)(this->map->width * this->map->tilewidth), (float)(this->map->height * this->map->tileheight)	 };
	this->frontiers = { 0, 0, (int)this->size.x, (int)this->size.y };

	this->camera = new Camera("Main Camera", { 0.0f, 0.0f }, &this->ctrl->window);

	this->player = new Player("Player", {0, 0}, ctrl->UI);
	for (int i = 0; i < MAX_ZOMBIES; i++) this->zombies[i] = NULL;
	for (int i = 0; i < MAX_BULLETS; i++) this->bullets[i] = NULL;

	this->kills = 0;
}


void World::Start() {
	this->player->dynamics.position = { (float)this->size.x / 2, (float)this->size.y / 2 };
}

void World::Update(float dtime) {
	this->map->Update(dtime);
	this->CheckCollisions();

	this->KeepPlayerIn(&this->player->dynamics, this->player->size);
	this->player->Update(dtime);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) {
		this->zombies[i]->WalkTo(this->player->dynamics.position, 32.0f);
		this->zombies[i]->Update(dtime);
		if (this->zombies[i]->IsDead()) {
			this->kills += 1;
			this->player->kills += 1;
			this->player->points += 100;
			this->zombies[i] = NULL;
			this->SpawnMissingZombies(i);
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) {
		this->bullets[i]->Update(dtime);
		if (this->bullets[i]->IsDead()) this->bullets[i] = NULL;
	}
}

void World::Render(SDL_Renderer* rdr) {
	SDL_RenderSetScale(rdr, this->camera->scale.x, this->camera->scale.y);
	this->map->Render(rdr, this->camera->position);

	this->player->Render(rdr, this->camera->position);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) this->zombies[i]->Render(rdr, this->camera->position);
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) this->bullets[i]->Render(rdr, this->camera->position);

	SDL_SetRenderDrawColor(rdr, 255, 0, 0, 255);
	SDL_RenderDrawRect(rdr, &this->frontiers);

	SDL_RenderSetScale(rdr, 1.0f, 1.0f);

	Vector2 center = this->player->dynamics.position;
	center.add(this->player->size, 0.5f);
	this->camera->CenterAt(center, this->size);

	this->frontiers.x = -this->camera->position.x;
	this->frontiers.y = -this->camera->position.y;
}

void World::PollEvent(SDL_Event ev) {
	this->player->PollEvent(ev);
}

void World::InitPlayers(int money) {
	this->player->kills = 0;
	this->player->money = money;
	this->player->points = money;
}

bool World::IsPlayerDead() { return this->player->IsDead(); }

void World::PlayerFire() {
	if (this->player->weapon->IsFiring()) if (this->player->weapon->Fire()) this->SpawnBullet(this->player->weapon);
}

void World::SpawnBullet(Weapon* weapon) {
	bool found = false;
	for (int i = 0; i < MAX_BULLETS && !found; i++) if (this->bullets[i] == NULL) {
		found = true;
		this->bullets[i] = new Bullet(weapon);
	}
}

void World::SpawnZombies(int population) {
	int spawned = 0;
	for (int i = 0; i < population; i++) {
		bool found = false;
		for (int j = 0; j < MAX_ZOMBIES && !found; j++) if (this->zombies[j] == NULL) {
			Vector2 position = { (float)(rand() % (int)this->size.x), (float)(rand() % (int)this->size.y) };
			this->zombies[j] = this->RoundZombie(this->round);
			this->zombies[j]->SetPosition(position);
			// this->zombies[j]->SetTileset(this->textures->at(0), { 0, 0, 32, 32 });
			found = true;
			spawned += 1;
		}
	}
	this->spawnedZombies += spawned;
}

void World::SpawnMissingZombies(int index) {
	if (this->totalZombies > MAX_ZOMBIES && this->spawnedZombies < this->totalZombies) {
		Vector2 position = { (float)(rand() % (int)this->size.x), (float)(rand() % (int)this->size.y) };
		this->zombies[index] = this->RoundZombie(this->round);
		this->zombies[index]->SetPosition(position);
		// this->zombies[index]->SetTexture(this->textures->at(0));
		this->spawnedZombies += 1;
	}
}

void World::CheckCollisions() {
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i] != NULL) {
		if (this->zombies[i]->square.IsNear(this->player->square)) if (this->zombies[i]->collider->CheckCollision(this->player->collider)) if (this->zombies[i]->DealDamage()) this->player->TakeDamage(1.0f);
		for (int j = 0; j < MAX_BULLETS; j++) if (this->bullets[j] != NULL) if (this->zombies[i]->square.IsNear(this->bullets[j]->square)) if (this->zombies[i]->collider->CheckCollision(this->bullets[j]->collider)) {
				this->zombies[i]->TakeDamage(this->bullets[j]->damage, 0);
				this->bullets[j]->Kill();
		}
		for (int j = 0; j < MAX_ZOMBIES; j++) if (i != j) if (this->zombies[j] != NULL) if (this->zombies[i]->square.IsNear(this->zombies[j]->square)) {
			Vector2 dist =  this->zombies[i]->collider->CheckCollisionDistance(this->zombies[j]->collider);
			if (dist.module() < 32.0f) {
				Vector2 disp = dist.unit();
				disp.scale(32.0f);
				disp.add(dist, -1.0f);
				this->zombies[i]->dynamics.acceleration.add(disp, -1 / pow(this->ctrl->GetDeltaTime(), 2));
			}
		}
	}
}

void World::KeepPlayerIn(Dynamics2* dynamics, Vector2 size) {
	if (dynamics->position.x <= 0 && dynamics->velocity.x < 0) { dynamics->velocity.x = 0; dynamics->position.x = 0; }
	if (dynamics->position.y <= 0 && dynamics->velocity.y < 0) { dynamics->velocity.y = 0; dynamics->position.y = 0; }
	if (dynamics->position.x + size.x >= this->size.x && dynamics->velocity.x > 0) { dynamics->velocity.x = 0; dynamics->position.x = this->size.x - size.x; }
	if (dynamics->position.y + size.y >= this->size.y && dynamics->velocity.y > 0) { dynamics->velocity.y = 0; dynamics->position.y = this->size.y - size.y; }
}


void World::NewRound(int zombies, int round) {
	this->kills = 0;
	this->spawnedZombies = 0;
	this->totalZombies = zombies;
	this->round = round;

	if (zombies <= MAX_ZOMBIES) this->SpawnZombies(zombies);
	else this->SpawnZombies(MAX_ZOMBIES);
}

Zombie* World::RoundZombie(int round) {
	Zombie* zombie = new Zombie("Zombie", { 0.0f, 0.0f });
	zombie->health = round * 2;
	zombie->speed = (rand() % 20) + 30.0f + 10.f * round;
	return zombie;
}


World::~World() {

}
