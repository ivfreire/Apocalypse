#pragma once
#include <iostream>
#include "entity.h"

class Weapon {
private:
	float firingBuffer;
	float rechargingBuffer;
	Vector2* position, * size;

public:
	std::string title;
	Face* facing;

	int maxAmmo, maxPaint;
	int currAmmo, currPaint;
	float cooldown;
	float mass;

	float bulletSpeed;
	float bulletMass;
	float damage;

	bool isFiring;


	Weapon(std::string title, Vector2* position, Vector2* size, Face* facing, float damage, float bulletSpeed, float bulletMass, int maxAmmo, int maxPaint, float mass, float cooldown);

	void Update(float dtime);

	bool Fire();
	Vector2 GetSpawnBulletPoint();

	~Weapon();

};
