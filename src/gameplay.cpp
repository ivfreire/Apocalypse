#include "gameplay.h"

Gameplay::Gameplay(Controller* ctrl) {
	this->world = new World();
}



void Gameplay::Start() {
	this->world->Start();
}

void Gameplay::Update(float dtime) {
	this->world->Update(dtime);
}

void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
}

void Gameplay::PollEvent(SDL_Event ev) {
	this->world->PollEvent(ev);
}



Gameplay::~Gameplay() {

}