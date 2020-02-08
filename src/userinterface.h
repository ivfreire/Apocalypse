#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "engine.h"

class UserInterface {
private:
	std::vector<SDL_Joystick*> joysticks;
	bool en_joystick;

public:
	std::vector<Vector2> axes;
	std::vector<float> joystick_axes;


	UserInterface();

	void PollEvent(SDL_Event ev);
	void InitJoystick();

	void Keyboard(SDL_Event ev);
	void Joystick(SDL_Event ev);

	Vector2 GetAxes(int id);
	float GetAxis(Axis axis, int id);
	bool HasJoysticks();

	~UserInterface();

};