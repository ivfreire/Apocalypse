#include "controller.h"

Controller::Controller(int width, int height) {
	this->window = { (float)width, (float)height };

	this->font = TTF_OpenFont("res/fonts/retro_gaming.ttf", 16);
	if (this->font == NULL) std::cerr << "ERROR" << std::endl;

	this->debugRect = { 10, 10, 300, 400 };

	this->showDebugInfo = false;
}


void Controller::Update(float dtime) {
	
}

void Controller::Render(SDL_Renderer* rdr) {
	if (this->showDebugInfo) {
		SDL_SetRenderDrawColor(rdr, 0, 0, 0, 100);
		SDL_RenderFillRect(rdr, &this->debugRect);

	}
}


void Controller::SetWindowSize() {
	int width, height;
	SDL_GetWindowSize(this->screen, &width, &height);
	this->window.x = (float)width;
	this->window.y = (float)height;
}


void Controller::CalculateFrameRate() {
	this->now = SDL_GetTicks();
	Uint32 dtick = this->now - this->before;
	this->dtime = (float)dtick / 1000.0f;
	before = SDL_GetTicks();;
	if (this->dtime > 0.016f) this->dtime = 0.016f;

	SDL_Delay((int)(1000.0f / MAX_FRAME_RATE));

	if (dtime != 0.0f) this->fps = (int)(1.0f / this->dtime);
}

float Controller::GetDeltaTime() {
	return this->dtime;
}


SDL_Texture* Controller::LoadImage(std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	return SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}


Controller::~Controller() {
	TTF_CloseFont(this->font);
}