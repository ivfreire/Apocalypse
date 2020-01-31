#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"
#include "userinterface.h"

class Player : public Entity {
private:
	UserInterface* UI;

public:
	Player(std::string title, Vector2 position, UserInterface* UI);

	void Update(float dtime);

	void Movement(float dtime);

	~Player();

};