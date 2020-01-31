#pragma once
#include <SDL2/SDL.h>
#include "engine.h"
#include "userinterface.h"

class Controller {
private:
	Uint32 now, before;
	float dtime;
	int fps;

public:
	Vector2 window;

	SDL_Window* screen;
	SDL_Renderer* renderer;

	UserInterface* UI;


	Controller(int width, int height);

	void SetWindowSize();

	void CalculateFrameRate();
	float GetDeltaTime();

	~Controller();

};