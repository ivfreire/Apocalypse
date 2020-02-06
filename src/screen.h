#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "graph.h"

#define MAX_GRAPHS	32
#define MAX_FONTS	4

class Screen {
private:
	Vector2* window;

public:
	std::vector<Graph*> graphs;
	std::vector<TTF_Font*> fonts;


	Screen(Vector2* window);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void LoadFont(std::string path, int size);

	~Screen();

};