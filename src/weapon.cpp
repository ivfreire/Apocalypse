#include "weapon.h"

Weapon::Weapon(std::string title, Vector2* position, Vector2* size, Face* facing, int maxPaint, int ammoPerPaint, float bulletSpeed, float bulletMass, float firingCooldown, float rechargeCooldown) {
	this->title = title;

	this->position = position;
	this->size = size;

	this->facing = facing;
	this->bulletSize = { 5.0f, 5.0f };

	this->maxPaint = maxPaint;
	this->ammoPerPaint = ammoPerPaint;

	this->bulletSpeed = bulletSpeed;
	this->bulletMass = bulletMass;

	this->cooldown[0] = firingCooldown;
	this->cooldown[1] = rechargeCooldown;

	this->buffer[0] = 0.0f;
	this->buffer[1] = 0.0f;

	this->infinite = false;
	this->firing = false;
	this->recharging = false;
}


void Weapon::Update(float dtime) {
	if (this->buffer[0] > 0) this->buffer[0] -= dtime;
	if (this->buffer[0] < 0) this->buffer[0] = 0.0f;

	this->bulletSpawn = { this->position->x + this->size->x / 2, this->position->y + this->size->y / 2 };
}


// Sets the weapon state to firing or not firing
void Weapon::StartFiring() { this->firing = true; }
void Weapon::StopFiring() { this->firing = false; }

// Verifies if the weapon is ready for firing
bool Weapon::Fire() {
	if (this->currAmmo > 0 || this->infinite) {
		if (this->buffer[0] == 0.0f) { this->buffer[0] = this->cooldown[0]; return true; }
		this->currAmmo -= 1;
	}
	return false;
}


bool Weapon::IsFiring() { return this->firing; }


Weapon::~Weapon() {

}