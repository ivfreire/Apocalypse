#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "engine.h"
#include "graph.h"

class Panel : public Graph {
private:


public:
	Panel(Vector2* window, Vector2 position, Vector2 size, SDL_Color color);
	~Panel();

};