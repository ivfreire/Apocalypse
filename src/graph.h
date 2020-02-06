#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"

class Graph {
private:
	SDL_Rect rect;

	SDL_Surface* surface;
	SDL_Texture* texture;

	Vector2* window;

public:
	Vector2 position, size;
	struct Relative { Vector2 position, size; } relative;

	SDL_Color color;
	SDL_Color outline_color;

	bool fill, outline;
	bool image;


	Graph(Vector2* window, Vector2 position, Vector2 size, SDL_Color color);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	
	void SetColor(SDL_Color color);
	void SetSurface(SDL_Surface* surface);
	void SetTexture(SDL_Texture* texture);

	SDL_Color GetColor();
	SDL_Surface* GetSurface();
	SDL_Texture* GetTexture();

	~Graph();

};