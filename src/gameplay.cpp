#include "gameplay.h"

Gameplay::Gameplay(Controller* ctrl) {
	this->ctrl = ctrl;
	this->world = new World(ctrl, "maps/test_scene2.xml");
	this->state = GameplayState::PLAYING;
	this->round = 0;

	// GAME MENU
	this->menu = new Screen(&ctrl->window);
	this->menu->LoadFont("res/fonts/retro_gaming.ttf", 22);
	this->menu->graphs.push_back(new Panel(&ctrl->window, { 0, 0 }, { 0, 0 }, { 0, 0, 0, 170 }));
	this->menu->graphs.back()->relative.size = { 1.0f, 1.0f };
	this->menu->graphs.push_back(new Text(&ctrl->window, "GAME MENU", this->menu->fonts.back(), { 0.0f, 0.0f }, { 255, 255, 255, 255 }, ctrl->renderer));
	this->menu->graphs.back()->relative.position = { 0.5f, 0.3f }; this->menu->graphs.back()->position.x = -this->menu->graphs.back()->size.x / 2;

	// HUD
	this->hud = new Screen(&ctrl->window);
	this->hud->LoadFont("res/fonts/retro_gaming.ttf", 72);
	this->hud->graphs.push_back(new Panel(&ctrl->window, { 8, 8 }, { 400, 8 }, { 255, 0, 0, 50 }));			// HEALTH BAR BACKGROUND
	this->hud->graphs.push_back(new Panel(&ctrl->window, { 8, 8 }, { 400, 8 }, { 255, 0, 0, 255 }));		// HEALTH BAR
	this->hud->graphs.back()->outline = true; this->hud->graphs.back()->outline_color = { 255, 255, 255, 255 };
}



void Gameplay::Start() {
	this->world->Start();
	this->world->InitPlayers(500);

	*this->current = 0;
}

void Gameplay::Update(float dtime) {
	if (this->state == GameplayState::PLAYING) {

		this->world->Update(dtime);
		this->world->PlayerFire();
		this->RoundControl();
		if (this->world->IsPlayerDead()) this->state = GameplayState::GAMEOVER;

		this->hud->graphs.at(1)->size.x = (int)(this->world->player->health * 100);

	} else if (this->state == GameplayState::PAUSED) {



	}
}

void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
}

void Gameplay::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_F3) this->ctrl->showDebugInfo = true;
		if (ev.key.keysym.sym == SDLK_ESCAPE && !this->lockEscape) {
			if (this->state == GameplayState::PAUSED) { this->state = GameplayState::PLAYING; *this->current = 0; }
			else { this->state = GameplayState::PAUSED; *this->current = 1; }
			this->lockEscape = true;
		}
	} else if (ev.type == SDL_KEYUP) {
		if (ev.key.keysym.sym == SDLK_ESCAPE) this->lockEscape = false;
		if (ev.key.keysym.sym == SDLK_F3) this->ctrl->showDebugInfo = false;
	}
	this->world->PollEvent(ev);
}


void Gameplay::RoundControl() {
	if (this->world->kills == this->ZombiesSpawnNumber(this->round)) this->NewRound();
}

void Gameplay::NewRound() {
	this->round += 1;

	int zombies = this->ZombiesSpawnNumber(this->round);
	this->world->NewRound(zombies, this->round);
}

int Gameplay::ZombiesSpawnNumber(int round) {
	return 5 * round;
}


Gameplay::~Gameplay() {

}