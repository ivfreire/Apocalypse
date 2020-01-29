#include "userinterface.h"

UserInterface::UserInterface() {

}


void UserInterface::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP) this->Keyboard(ev);
}

void UserInterface::Keyboard(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_w) this->axes[0].set(Axis::VERTICAL,	-1.0f);
		if (ev.key.keysym.sym == SDLK_a) this->axes[0].set(Axis::HORIZONTAL,	-1.0f);
		if (ev.key.keysym.sym == SDLK_s) this->axes[0].set(Axis::VERTICAL,	 1.0f);
		if (ev.key.keysym.sym == SDLK_d) this->axes[0].set(Axis::HORIZONTAL,	 1.0f);
	} else {
		if (ev.key.keysym.sym == SDLK_w) this->axes[0].set(Axis::VERTICAL,	-0.0f);
		if (ev.key.keysym.sym == SDLK_a) this->axes[0].set(Axis::HORIZONTAL,	-0.0f);
		if (ev.key.keysym.sym == SDLK_s) this->axes[0].set(Axis::VERTICAL,	 0.0f);
		if (ev.key.keysym.sym == SDLK_d) this->axes[0].set(Axis::HORIZONTAL,	 0.0f);
	}
}


float UserInterface::GetAxis(Axis axis, int id) {
	if (axis == Axis::HORIZONTAL) return this->axes[id].x;
	if (axis == Axis::VERTICAL) return this->axes[id].y;
	return 0.0f;
}


UserInterface::~UserInterface() {

}