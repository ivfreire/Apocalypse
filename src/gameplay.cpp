#include "gameplay.h"

Gameplay::Gameplay(Controller* ctrl) {
	this->ctrl = ctrl;
	this->world = new World(ctrl);
}



void Gameplay::Start() {
	this->world->Start();
}

void Gameplay::Update(float dtime) {
	this->world->Update(dtime);
}

void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
	this->world->PlayerFire();
}

void Gameplay::PollEvent(SDL_Event ev) {
	this->world->PollEvent(ev);
}



Gameplay::~Gameplay() {

}