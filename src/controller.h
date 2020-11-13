#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "userinterface.h"
#include "tileset.h"

#define MAX_FRAME_RATE	120

class Controller {
private:
	Uint32 now, before;
	float dtime;
	int fps;

	SDL_Rect debugRect;

public:
	Vector2 window;

	SDL_Window* screen;
	SDL_Renderer* renderer;

	UserInterface* UI;

	TTF_Font* font;

	bool showDebugInfo;


	Controller(int width, int height);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void SetWindowSize();

	void CalculateFrameRate();
	float GetDeltaTime();

	SDL_Texture* LoadImage(std::string path);

	~Controller();

};