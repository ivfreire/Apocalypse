#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"

class Player : public Entity {
private:


public:
	Player(std::string title, Vector2 position);
	~Player();

};