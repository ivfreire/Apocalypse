#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"

class Zombie : public Entity {
private:


public:
	int id;


	Zombie(std::string title, Vector2 position);

	void WalkTo(Vector2 position, float tolerance);

	void TakeDamage(int damage, int id);

	~Zombie();

};