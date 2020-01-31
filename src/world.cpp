#include "world.h"

World::World(Controller* ctrl) {
	srand(time(NULL));

	this->ctrl = ctrl;

	this->player = new Player("Player", {0, 0}, ctrl->UI);

	for (int i = 0; i < MAX_ZOMBIES; i++) this->zombies[i] = NULL;
}


void World::Start() {
	this->SpawnZombies(4);
}

void World::Update(float dtime) {
	this->player->Update(dtime);

	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) {
		this->zombies[i]->WalkTo(this->player->dynamics.position, 50.0f);
		this->zombies[i]->Update(dtime);
	}
}

void World::Render(SDL_Renderer* rdr) {
	this->player->Render(rdr);
	for (int i = 0; i < MAX_ZOMBIES; i++) if (this->zombies[i]) this->zombies[i]->Render(rdr);
}

void World::PollEvent(SDL_Event ev) {

}


void World::SpawnZombies(int population) {
	for (int i = 0; i < population; i++) {
		bool found = false;
		for (int j = 0; j < MAX_ZOMBIES && !found; j++) if (this->zombies[j] == NULL) {
			this->zombies[j] = new Zombie("Zombie", { rand() % (int)ctrl->window.x, rand() % (int)this->ctrl->window.y });
			found = true;
		}
	}
}


World::~World() {

}