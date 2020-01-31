#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.h"

class Collider {
private:
	SDL_Rect rect;

public:
	Vector2 * position, * size;


	Collider(Vector2* position, Vector2* size);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	~Collider();

};