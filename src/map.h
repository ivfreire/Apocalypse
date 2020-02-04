#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <tinyxml2.h>
#include "engine.h"
#include "tileset.h"

#define MAX_TILESETS	4
#define MAX_LAYERS		8
#define MAX_WORLDSIZE	1024

class Map {
private:


public:
	int width, height;
	int tilewidth, tileheight;

	Tileset* tilesets[MAX_TILESETS];
	SDL_Texture* layers[MAX_LAYERS];


	Map(std::string path);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	~Map();

};