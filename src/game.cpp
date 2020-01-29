#include "game.h"

Game::Game(Controller* ctrl) {
	this->ctrl = ctrl;
	this->rdr = this->ctrl->renderer;

	this->running = true;

	this->gameplay = new Gameplay(this->ctrl);
}



void Game::Start() {
	this->gameplay->Start();
}

void Game::Update() {
	this->ctrl->CalculateFrameRate();
	this->gameplay->Update(this->ctrl->GetDeltaTime());
}

void Game::Render() {
	SDL_SetRenderDrawColor(this->rdr, 255, 255, 255, 255);
	SDL_RenderClear(this->rdr);

	this->gameplay->Render(this->rdr);

	SDL_RenderPresent(this->rdr);
}

void Game::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) if (ev.key.keysym.sym == SDLK_ESCAPE) this->GameOver();
	this->gameplay->PollEvent(ev);
}



void Game::GameOver() {
	this->running = false;
}

bool Game::IsOver() {
	return !this->running;
}



Game::~Game() {

}