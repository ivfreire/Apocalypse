#include "userinterface.h"

UserInterface::UserInterface() {
	this->en_joystick = false;
	if (SDL_NumJoysticks() > 0) this->InitJoystick();

	this->axes.push_back({ 0.0f, 0.0f });
}


void UserInterface::PollEvent(SDL_Event ev) {
	this->Keyboard(ev);
	if (this->en_joystick) this->Joystick(ev);
}

void UserInterface::InitJoystick() {
	this->joysticks.push_back(SDL_JoystickOpen(0));

	std::cout << SDL_JoystickName(this->joysticks.at(0)) << "\t" << SDL_JoystickNumAxes(this->joysticks.at(0)) << "\t";
	std::cout  << SDL_JoystickNumHats(this->joysticks.at(0)) << "\t" << std::endl;

	for (int i = 0; i < SDL_JoystickNumAxes(this->joysticks.at(0)); i++) this->joystick_axes.push_back(0.0f);

	this->en_joystick = true;
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
		Vector2 motion = { (float)SDL_JoystickGetAxis(this->joysticks.at(0), 0), (float)SDL_JoystickGetAxis(this->joysticks.at(0), 1) };
		motion.scale(1.0f / motion.module());
		if (motion.module() > 0.19f) this->axes[0] = motion;
		else this->axes[0] = { 0.0f , 0.0f };
	}
}


Vector2 UserInterface::GetAxes(int id) { return this->axes.at(id); }
float UserInterface::GetAxis(Axis axis, int id) { return this->axes.at(id).get(axis); }
bool UserInterface::HasJoysticks() { return this->en_joystick; }


UserInterface::~UserInterface() {

}