#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <tinyxml2.h>
#include "engine.h"

#define MAX_TILES	256

class Tileset {
private:


public:
	int firstgid;
	std::string name;
	int tilewidth, tileheight;
	int tilecount, columns;


	SDL_Surface* surface;
	SDL_Texture* texture;

	SDL_Surface* tiles[MAX_TILES];


	Tileset(int firstgid, std::string path);


	~Tileset();

};