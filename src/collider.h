#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "engine.h"

enum class ColliderShape { BOX, CIRCLE, POLYGON };

class Collider {
private:
	Vector2* position, * size;
	SDL_Rect rect;

public:
	std::string title;
	ColliderShape shape;


	Collider(std::string title, ColliderShape shape, Vector2* position, Vector2* size);

	void Update();
	void Render(SDL_Renderer* rdr);

	~Collider();

};