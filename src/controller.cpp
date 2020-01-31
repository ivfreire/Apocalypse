#include "controller.h"

Controller::Controller(int width, int height) {
	this->window = { (float)width, (float)height };
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

	if (dtime != 0.0f) this->fps = (int)(1.0f / this->dtime);
}

float Controller::GetDeltaTime() {
	return this->dtime;
}


Controller::~Controller() {

}