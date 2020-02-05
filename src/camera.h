#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "engine.h"

class Camera {
private:
	Vector2* screen;

public:
	std::string title;
	Vector2 position;

	Vector2 scale;

	Camera(std::string title, Vector2 position, Vector2* screen);

	void CenterAt(Vector2 position);

	~Camera();

};