#include "gameplay.h"

Gameplay::Gameplay(Controller* ctrl) {
	this->ctrl = ctrl;
	this->world = new World(ctrl, "maps/lobby.xml");
	this->state = GameplayState::PLAYING;
	this->round = 0;

	this->menu = new Screen(&ctrl->window);
	this->menu->LoadFont("res/fonts/retro_gaming.ttf", 20);
	this->menu->graphs[0] = new Text("GAME MENU", this->menu->fonts[0], { 255, 255, 255 }, ctrl->renderer);
	this->menu->graphs[0]->centered = true;
}



void Gameplay::Start() {
	this->world->Start();
	this->world->InitPlayers(500);
}

void Gameplay::Update(float dtime) {
	if (this->state == GameplayState::PLAYING) {
		this->world->Update(dtime);
		this->world->PlayerFire();

		this->RoundControl();
		// this->hud->graphs[0] = new Text(std::to_string(this->world->player->health), this->hud->fonts[0], { 0, 0, 0 }, this->ctrl->renderer);

		if (this->world->IsPlayerDead()) this->state = GameplayState::GAMEOVER;
	} else if (this->state == GameplayState::PAUSED) {
		this->background = { 0, 0, (int)this->ctrl->window.x, (int)this->ctrl->window.y };
	}
}

void Gameplay::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
	if (this->state == GameplayState::PAUSED) {
		SDL_SetRenderDrawBlendMode(ctrl->renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(rdr, 0, 0, 0, 150);
		SDL_RenderFillRect(rdr, &this->background);
	}
}

void Gameplay::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_F3) this->ctrl->showDebugInfo = true;
		if (ev.key.keysym.sym == SDLK_ESCAPE && !this->lockEscape) {
			if (this->state == GameplayState::PAUSED) { this->state = GameplayState::PLAYING; *this->current = -1; }
			else { this->state = GameplayState::PAUSED; *this->current = 0; }
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
	std::cout << "New Round: " << this->round << std::endl;
}

int Gameplay::ZombiesSpawnNumber(int round) {
	return 5 * round;
}


Gameplay::~Gameplay() {

}