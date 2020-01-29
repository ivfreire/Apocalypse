#pragma once
#include <string>
#include "userinterface.h"
#include "entity.h"
#include "weapon.h"

class Player : public Entity {
private:
	UserInterface* UI;

public:
	Weapon* weapon, * otherWeapon;


	Player(std::string title, float x, float y, UserInterface* UI);

	void Update(float dtime);
	void PollEvent(SDL_Event ev);

	void Movement();

	~Player();

};