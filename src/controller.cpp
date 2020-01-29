#include "controller.h"

Controller::Controller(int width, int height) {
	this->window = { (float)width, (float)height };
}


void Controller::CalculateFrameRate() {
	this->now = SDL_GetTicks();
	Uint32 dtick = this->now - this->before;
	this->dtime = (float)dtick / 1000.0f;
	before = now;
	if (this->dtime > 0.016f) this->dtime = 0.016f;
}

float Controller::GetDeltaTime() {
	return this->dtime;
}


Controller::~Controller() {

}