#include "world.h"

World::World(Controller* ctrl, Vector2 size, Vector2 tilesize) {
	srand(time(NULL));

	this->ctrl = ctrl;
	this->size = size;
	this->tilesize = tilesize;

	this->camera = new Camera("Main Camera", { 0.0f, 0.0f }, &this->ctrl->window);

	this->player = new Player("Player", {0, 0}, ctrl->UI);
	for (int i = 0; i < MAX_ZOMBIES; i++) this->zombies[i] = NULL;
	for (int i = 0; i < MAX_BULLETS; i++) this->bullets[i] = NULL;
}


void World::Start() {
	this->SpawnZombies(64);
}

void World::Update(float dtime) {
	this->CheckCollisions();

	this->player->Update(dtime);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) {
		this->zombies[i]->WalkTo(this->player->dynamics.position, 32.0f);
		this->zombies[i]->Update(dtime);
		if (this->zombies[i]->IsDead()) this->zombies[i] = NULL;
	}
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) {
		this->bullets[i]->Update(dtime);
		if (this->bullets[i]->IsDead()) this->bullets[i] = NULL;
	}

	Vector2 center = this->player->dynamics.position;
	center.add(this->player->size, 0.5f);
	this->camera->CenterAt(center);
}

void World::Render(SDL_Renderer* rdr) {
	this->player->Render(rdr, this->camera->position);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) this->zombies[i]->Render(rdr, this->camera->position);
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) this->bullets[i]->Render(rdr, this->camera->position);
}

void World::PollEvent(SDL_Event ev) {
	this->player->PollEvent(ev);
}


void World::PlayerFire() {
	if (this->player->weapon->IsFiring()) if (this->player->weapon->Fire()) this->SpawnBullet(this->player->weapon);
}

void World::SpawnBullet(Weapon* weapon) {
	bool found = false;
	for (int i = 0; i < MAX_BULLETS && !found; i++) if (this->bullets[i] == NULL) { found = true; this->bullets[i] = new Bullet(weapon); }
}

void World::SpawnZombies(int population) {
	for (int i = 0; i < population; i++) {
		bool found = false;
		for (int j = 0; j < MAX_ZOMBIES && !found; j++) if (this->zombies[j] == NULL) {
			Vector2 position = { (float)(rand() % (int)ctrl->window.x), (float)(rand() % (int)this->ctrl->window.y) };
			this->zombies[j] = new Zombie("Zombie", position);
			found = true;
		}
	}
}

void World::CheckCollisions() {
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) {
		if (this->zombies[i]->collider->CheckCollision(this->player->collider)) this->player->TakeDamage(1);
		for (int j = 0; j < MAX_BULLETS; j++) if (this->bullets[j]) if (!this->bullets[j]->IsDead()) if (this->zombies[i]->collider->CheckCollision(this->bullets[j]->collider)) {
			this->zombies[i]->TakeDamage(1);
			this->bullets[j]->OnCollision();
		}
	}
}


World::~World() {

}