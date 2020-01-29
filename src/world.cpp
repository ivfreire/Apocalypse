#include "world.h"

World::World() {
	this->player = new Player("Player", {0, 0});
}


void World::Start() {

}

void World::Update(float dtime) {
	this->player->Update(dtime);
}

void World::Render(SDL_Renderer* rdr) {
	this->player->Render(rdr);
}

void World::PollEvent(SDL_Event ev) {

}


World::~World() {

}