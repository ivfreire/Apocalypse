#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "screen.h"

#define MAX_SCREENS	8

class GUI {
private:
	Vector2* window;

public:
	int current;
	Screen* screens[MAX_SCREENS];


	GUI(Vector2* window);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void AddScreen(Screen* screen);

	~GUI();

};