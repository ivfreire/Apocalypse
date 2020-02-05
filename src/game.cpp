#include "game.h"

Game::Game(Controller* ctrl) {
	this->state = GameState::GAMEPLAY;
	this->background = { 29, 25, 41, 255};

	this->ctrl = ctrl;
	this->rdr = this->ctrl->renderer;

	this->running = true;

	this->UI = new UserInterface();
	this->ctrl->UI = this->UI;

	this->gui = new GUI(&ctrl->window);
	this->gameplay = new Gameplay(this->ctrl);
	this->gameplay->current = &this->gui->current;

	this->gui->screens[0] = this->gameplay->menu;
}



void Game::Start() {
	this->gameplay->Start();
}

void Game::Update() {
	this->ctrl->CalculateFrameRate();
	this->gameplay->Update(this->ctrl->GetDeltaTime());
	this->ctrl->SetWindowSize();
	this->gui->Update(this->ctrl->GetDeltaTime());
}

void Game::Render() {
	SDL_SetRenderDrawColor(this->rdr, this->background.r, this->background.g, this->background.b, this->background.a);
	SDL_RenderClear(this->rdr);

	this->gameplay->Render(this->rdr);
	this->gui->Render(this->ctrl->renderer);
	this->ctrl->Render(this->rdr);

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
	this->gui->~GUI();
}