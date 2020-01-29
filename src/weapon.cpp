#include "weapon.h"

Weapon::Weapon(std::string title, Vector2* position, Vector2* size, Face* facing, float damage, float bulletSpeed, float bulletMass, int maxAmmo, int maxPaint, float mass, float cooldown) {
	this->title = title;

	this->facing = facing;
	this->damage = damage;
	this->bulletSpeed = bulletSpeed;
	this->bulletMass = bulletMass;
	this->maxAmmo = maxAmmo;
	this->maxPaint = maxPaint;
	this->mass = mass;
	this->cooldown = cooldown;

	this->currAmmo = maxAmmo;
	this->currPaint = maxPaint;

	this->firingBuffer = 0.0f;
	this->rechargingBuffer = 0.0f;

	this->position = position;
	this->size = size;

	this->isFiring = false;
}

void Weapon::Update(float dtime) {
	if (this->firingBuffer != 0.0f) {
		this->firingBuffer -= dtime;
		if (this->firingBuffer < 0) this->firingBuffer = 0.0f;
	}
}

bool Weapon::Fire() {
	if ((this->currAmmo > 0 && this->firingBuffer == 0.0f) || (this->maxAmmo == 0 && this->firingBuffer == 0.0f)) {
		this->firingBuffer = this->cooldown;
		this->currAmmo -= 1;
		return true;
	}
	return false;
}

Vector2 Weapon::GetSpawnBulletPoint() {
	Vector2 spawn, _size;
	spawn = *this->position;
	spawn.add(*this->size, 0.5f);
	return spawn;
}

Weapon::~Weapon() {

}