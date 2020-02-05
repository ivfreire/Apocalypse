#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <tinyxml2.h>
#include "engine.h"

class Tileset {
private:
	std::vector<SDL_Surface*> tiles;

public:
	int firstgid;
	std::string name;
	int tilewidth, tileheight;
	int tilecount, columns;


	SDL_Surface* surface;
	SDL_Texture* texture;


	Tileset(int firstgid, std::string path);

	SDL_Surface* GetTile(int id);

	~Tileset();

};