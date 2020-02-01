#pragma once

#include <iostream>
#include <string>
#include "engine.h"

class Camera {
private:
	Vector2* screen;

public:
	std::string title;
	Vector2 position;
	

	Camera(std::string title, Vector2 position, Vector2* screen);

	void CenterAt(Vector2 position);

	~Camera();

};