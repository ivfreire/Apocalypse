#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"
#include "userinterface.h"
#include "weapon.h"

class Player : public Entity {
private:
	UserInterface* UI;

public:
	Weapon* weapon, * secWeapon;

	int points, money, kills;


	Player(std::string title, Vector2 position, UserInterface* UI);

	void Update(float dtime);
	void PollEvent(SDL_Event ev);

	void Movement(float dtime);
	void SetFacing();
	void TakeDamage(float damage);

	void Regenerate(float rate, float dtime);

	~Player();

};