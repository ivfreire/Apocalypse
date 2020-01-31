#include "game.h"

Game::Game(Controller* ctrl) {
	this->ctrl = ctrl;
	this->rdr = this->ctrl->renderer;

	this->running = true;

	this->UI = new UserInterface();
	this->ctrl->UI = this->UI;

	this->gameplay = new Gameplay(this->ctrl);

	SDL_SetRenderDrawBlendMode(ctrl->renderer, SDL_BLENDMODE_BLEND);
}



void Game::Start() {
	this->gameplay->Start();
}

void Game::Update() {
	this->ctrl->CalculateFrameRate();
	this->gameplay->Update(this->ctrl->GetDeltaTime());
	this->ctrl->SetWindowSize();
}

void Game::Render() {
	SDL_SetRenderDrawColor(this->rdr, 255, 255, 255, 255);
	SDL_RenderClear(this->rdr);

	this->gameplay->Render(this->rdr);

	SDL_RenderPresent(this->rdr);
}

void Game::PollEvent(SDL_Event ev) {
	this->UI->PollEvent(ev);
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