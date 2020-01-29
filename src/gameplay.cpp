#include "gameplay.h"

Gameplay::Gameplay(UserInterface* UI) {
	this->UI = UI;
	this->world = new World(this->UI);

	this->state = GameplayState::PLAYING;
}


// Starts gameplay
void Gameplay::Start() {
	this->buffer = 0;
	this->world->Start();
}

// Updates gameplay
void Gameplay::Update(float dtime) {
	if (!this->IsPaused()) this->world->Update(dtime);
}

// Render's gameplay
void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);

	if (this->IsPaused()) {
		this->background = { 0, 0, *width, *height };
		SDL_SetRenderDrawColor(rdr, 0, 0, 0, 150);
		SDL_RenderFillRect(rdr, &this->background);
	}
}

// Captures users input
void Gameplay::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_ESCAPE) {
			//if (this->state == GameplayState::PLAYING) { this->state = GameplayState::PAUSED; std::cout << "asd" << std::endl;}
			//if (this->state == GameplayState::PAUSED) this->state = GameplayState::PLAYING;
		}
	}

	// PLAYING EVENTS
	if (this->state == GameplayState::PLAYING) {
		if (ev.type == SDL_KEYDOWN) {
			//if (ev.key.keysym.sym == SDLK_SPACE) this->world->PlayerFire();
		}
	}

	this->world->player->PollEvent(ev);
}


// Sets the window's size
void Gameplay::SetWindowSize(int* width, int* height) {
	this->width = width;
	this->height = height;
	this->world->SetWindowSize(width, height);
}


// Gets the current gameplay's state
bool Gameplay::IsPaused() {
	if (this->state == GameplayState::PAUSED) return true;
	else return false;
}


Gameplay::~Gameplay() {
	this->world->~World();
}