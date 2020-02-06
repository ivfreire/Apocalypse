#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "graph.h"

class Text : public Graph {
private:


public:
	Text(Vector2* window, std::string text, TTF_Font* font, Vector2 position, SDL_Color color, SDL_Renderer* rdr);

	void SetText(std::string text, TTF_Font* font, SDL_Renderer* rdr);

	~Text();

};