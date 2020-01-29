#pragma once
#include <SDL2/SDL.h>
#include "engine.h"

class Controller {
private:
	Uint32 now, before;
	float dtime;

public:
	Vector2 window;

	SDL_Renderer* renderer;


	Controller(int width, int height);

	void CalculateFrameRate();
	float GetDeltaTime();

	~Controller();

};