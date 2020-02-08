#pragma once

#include <iostream>
#include <string>
#include <cmath>

enum class Axis { HORIZONTAL, VERTICAL };

struct Vector2 {
	float x, y;
	void set(Axis axis, float value) { if (axis == Axis::HORIZONTAL) this->x = value; if (axis == Axis::VERTICAL) this->y = value; };
	float get(Axis axis) { if (axis == Axis::HORIZONTAL) return this->x; if (axis == Axis::VERTICAL) return this->y; return 0.0f; };
	void add(Vector2 vec, float factor) { this->x += vec.x * factor; this->y += vec.y * factor; };
	void scale(float factor) { this->x = this->x * factor; this->y = this->y * factor; };
	float module() { return sqrt(pow(this->x, 2) + pow(this->y, 2)); };
	Vector2 unit() { Vector2 uni; uni.x = this->x; uni.y = this->y; uni.scale(1.0f / uni.module()); return uni; };
};

/*

	(x1, y1) = (5, 7)
	4 <= x2 <= 6	x1 - 1 <= x2 <= x1 + 1
	6 <= y2 <= 8	y1 - 1 <= y2 <= y2 + 1

*/

struct Int2 {
	int x, y;
	bool IsNear(Int2 other) {
		if ((other.x >= this->x - 1 || other.x <= this->x + 1) &&(other.y >= this->y -1 || other.y <= this->y + 1)) return true;
		return false;
	}
};

struct Dynamics2 {
	Vector2 position, velocity, acceleration;
};