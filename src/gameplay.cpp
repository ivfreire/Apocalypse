#include "gameplay.h"

Gameplay::Gameplay(Controller* ctrl) {
	this->ctrl = ctrl;
	this->world = new World(ctrl, { 1024, 1024 }, { 32, 32 });

	this->state = GameplayState::PLAYING;
}



void Gameplay::Start() {
	this->world->Start();
}

void Gameplay::Update(float dtime) {
	if (this->state == GameplayState::PLAYING) {
		this->world->Update(dtime);
		this->world->PlayerFire();
	} else {
		this->background = { 0, 0, (int)this->ctrl->window.x, (int)this->ctrl->window.y };
	}
}

void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
	if (this->state == GameplayState::PAUSED) {
		SDL_SetRenderDrawColor(rdr, 0, 0, 0, 150);
		SDL_RenderFillRect(rdr, &this->background);
	}
}

void Gameplay::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_ESCAPE && !this->lockEscape) {
			if (this->state == GameplayState::PAUSED) this->state = GameplayState::PLAYING;
			else this->state = GameplayState::PAUSED;
			this->lockEscape = true;
		}
	} else if (ev.type == SDL_KEYUP) {
		if (ev.key.keysym.sym == SDLK_ESCAPE) this->lockEscape = false;
	}
	this->world->PollEvent(ev);
}



Gameplay::~Gameplay() {

}