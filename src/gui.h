#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "screen.h"

class GUI {
private:
	Vector2* window;

public:
	int current;
	std::vector<Screen*> screens;


	GUI(Vector2* window);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void AddScreen(Screen* screen);

	~GUI();

};