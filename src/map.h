#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <tinyxml2.h>
#include "engine.h"
#include "tileset.h"
#include "camera.h"

#define MAX_TILESETS	4
#define MAX_WORLDSIZE	1024


struct Layer {
	int id;
	std::string name;
	int width, height;
	std::vector<int> data;
	SDL_Texture* texture;

	SDL_Rect rect;
};

class Map {
private:
	std::vector<std::string> SplitString(std::string input, char pattern);
	SDL_Surface* GetTile(int id);

	std::vector<Layer> layers;

public:
	int width, height;
	int tilewidth, tileheight;

	std::vector<Tileset*> tilesets;


	Map(std::string path);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr, Vector2 camera);

	void RenderLayers(SDL_Renderer* rdr);

	~Map();

};