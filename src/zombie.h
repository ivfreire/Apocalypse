#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"

class Zombie : public Entity {
private:
	float buffer;

public:
	int id;


	Zombie(std::string title, Vector2 position);

	void Update(float dtime);

	void WalkTo(Vector2 position, float tolerance);

	bool DealDamage();
	void TakeDamage(float damage, int id);

	~Zombie();

};