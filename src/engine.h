#pragma once

#include <iostream>
#include <string>

enum class Axis { HORIZONTAL, VERTICAL };

struct Vector2 {
	float x, y;
	void add(Vector2 vec, float factor) { this->x += vec.x * factor; this->y += vec.y * factor; };
};

struct Dynamics2 {
	Vector2 position, velocity, acceleration;
};