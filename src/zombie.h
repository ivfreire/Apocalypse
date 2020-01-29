#pragma once
#include <string>
#include "entity.h"

class Zombie : public Entity {
private:


public:
	Zombie(std::string title, float x, float y);

	void WalkTo(Vector2 destination, float tolerance);

	~Zombie();

};