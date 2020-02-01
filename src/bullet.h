#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "entity.h"
#include "weapon.h"

class Bullet : public Entity {
private:


public:
	Bullet(Vector2 position, Face facing, float speed, float mass);
	Bullet(Weapon* weapon);

	void SetVelocity();

	void OnCollision();

	~Bullet();

};