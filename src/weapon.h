#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "entity.h"
#include "engine.h"

class Weapon {
private:
	Vector2* position, * size;
	bool firing, recharging;
	float buffer[1];				// 0 -> FIRERING    1-> RECHARGING

public:
	std::string title;
	Vector2 bulletSpawn;

	float bulletSpeed;
	float bulletMass;
	Vector2 bulletSize;
	float cooldown[1];

	Face* facing;
	int id;

	int maxPaint, ammoPerPaint;
	int currAmmo, currPaint;

	bool infinite;


	Weapon(std::string title, Vector2* position, Vector2* size, Face* facing, int maxPaint, int ammoPerPaint, float bulletSpeed, float bulletMass, float firingCooldown, float rechargeCooldown);

	void Update(float dtime);

	void StartFiring();
	void StopFiring();
	void Recharge();
	bool Fire();

	bool IsFiring();

	~Weapon();

};