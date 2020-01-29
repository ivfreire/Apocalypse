#include "world.h"

World::World(UserInterface* UI) {
	this->UI = UI;

	this->player = new Player("Player", 0, 0, this->UI);

	for (int i = 0; i < MAX_ZOMBIES; i++) this->zombies[i] = nullptr;
	for (int i = 0; i < MAX_BULLETS; i++) this->bullets[i] = nullptr;
}


void World::Start() {
	this->player->Start();

	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) this->zombies[i]->Start();
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) this->bullets[i]->Start();

	this->SpawnZombies(10);
}

void World::Update(float dtime) {
	this->player->Update(dtime);

	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) {
		this->zombies[i]->WalkTo(this->player->dynamics.position, 50.0f);
		this->zombies[i]->Update(dtime);
	}
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) {
		this->bullets[i]->Update(dtime);
		if (this->bullets[i]->IsDead()) this->bullets[i] = nullptr;
	}

	if (this->player->weapon->isFiring) this->PlayerFire();
}

void World::Render(SDL_Renderer* rdr) {
	this->player->Render(rdr);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) this->zombies[i]->Render(rdr);
	for (int i = 0; i < MAX_BULLETS; i++) if (this->bullets[i]) this->bullets[i]->Render(rdr);
}


// Spawns zombies in the world
void World::SpawnZombies(int population) {
	for (int i = 0; i < population; i++) {
		bool found = false;
		for (int j = 0; j < MAX_ZOMBIES && !found; j++) {
			if (!this->zombies[j]) {
				this->zombies[j] = new Zombie("Zombie", rand() % *width, rand() % *height);
				found = true;
			}
		}
	}
}

// Makes the player shoot
void World::PlayerFire() {
	if (this->player->weapon->Fire()) {
		bool found = false;
		for (int i = 0; i < MAX_BULLETS && !found; i++) {
			if (!this->bullets[i]) {
				found = true;
				this->bullets[i] = new Bullet(this->player->weapon->GetSpawnBulletPoint(), this->player->facing, this->player->weapon->bulletSpeed, 5.0f);
			}
		}
	}
}


// Get's the screen size
void World::SetWindowSize(int* width, int* height) {
	this->width = width;
	this->height = height;
}


World::~World() {
	this->player->~Player();
	for (int i = 0; i < MAX_ZOMBIES; i++) this->zombies[i] = nullptr;
	for (int i = 0; i < MAX_BULLETS; i++) this->bullets[i] = nullptr;
}