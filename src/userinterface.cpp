#include "userinterface.h"

UserInterface::UserInterface() {
	for (int i = 0; i < MAX_AXES; i++) this->axes[i] = { 0.0f, 0.0f };
	for (int i = 0; i < MAX_JOYSTICKS; i++) this->joysticks[i] = NULL;

	this->en_joystick = false;
	if (SDL_NumJoysticks() > 0) this->InitJoystick();
}


void UserInterface::PollEvent(SDL_Event ev) {
	this->Keyboard(ev);
	this->Joystick(ev);
}

void UserInterface::InitJoystick() {
	bool found = false;
	for (int i = 0; i < MAX_JOYSTICKS && !found; i++) {
		found = true;
		this->joysticks[i] = SDL_JoystickOpen(i);
		this->en_joystick = true;
	}
}


void UserInterface::Keyboard(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_w) this->axes[0].set(Axis::VERTICAL, 	   -1.0f);
		if (ev.key.keysym.sym == SDLK_a) this->axes[0].set(Axis::HORIZONTAL,   -1.0f);
		if (ev.key.keysym.sym == SDLK_s) this->axes[0].set(Axis::VERTICAL, 		1.0f);
		if (ev.key.keysym.sym == SDLK_d) this->axes[0].set(Axis::HORIZONTAL,	1.0f);
	} else if (ev.type == SDL_KEYUP) {
		if (ev.key.keysym.sym == SDLK_w) this->axes[0].set(Axis::VERTICAL,		0.0f);
		if (ev.key.keysym.sym == SDLK_a) this->axes[0].set(Axis::HORIZONTAL,	0.0f);
		if (ev.key.keysym.sym == SDLK_s) this->axes[0].set(Axis::VERTICAL,		0.0f);
		if (ev.key.keysym.sym == SDLK_d) this->axes[0].set(Axis::HORIZONTAL,	0.0f);
	}
}

void UserInterface::Joystick(SDL_Event ev) {
	if (ev.type == SDL_JOYAXISMOTION) {
		Vector2 motion.set(SDL_JoystickGetAxis());
		this->axes[0] = {  };
	}
}


Vector2 UserInterface::GetAxes(int id) {
	return this->axes[id];
}

float UserInterface::GetAxis(Axis axis, int id) {
	return this->axes[id].get(axis);
}


UserInterface::~UserInterface() {

}