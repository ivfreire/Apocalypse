#pragma once
#include <iostream>
#include "entity.h"
#include "engine.h"

class Bullet : public Entity {
private:


public:
	Bullet(Vector2 position, Face facing, float speed, float lifetime);

	~Bullet();

};