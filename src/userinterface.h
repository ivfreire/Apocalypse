#pragma once

#include <SDL2/SDL.h>
#include "engine.h"

#define MAX_JOYSTICKS	4
#define MAX_AXES 8

class UserInterface {
private:
	SDL_Joystick* joysticks[MAX_JOYSTICKS];
	bool en_joystick;

public:
	Vector2 axes[MAX_AXES];


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