#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"

class Graph {
private:
	SDL_Color color;

	SDL_Surface* surface;
	SDL_Texture* texture;

public:
	SDL_Rect rect;
	Vector2 position, size;
	bool centered;


	Graph();

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void SetColor(SDL_Color color);
	void SetSurface(SDL_Surface* surface);
	void SetTexture(SDL_Texture* texture);
	SDL_Color GetColor();
	SDL_Surface* GetSurface();

	~Graph();

};