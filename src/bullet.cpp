#include "bullet.h"

Bullet::Bullet(Vector2 position, Face facing, float speed, float mass) : Entity("Bullet", position, { 10.0f, 10.0f }, EntityType::BULLET) {
	this->speed = speed;
	this->mass = mass;
	this->facing = facing;

	this->color = { 0, 0, 255, 255 };
	this->damage = 4;

	this->SetLife(1.0f);

	this->SetVelocity();
}

Bullet::Bullet(Weapon* weapon) : Entity("Bullet", weapon->bulletSpawn, weapon->bulletSize, EntityType::BULLET) {
	this->facing = *weapon->facing;
	this->speed = weapon->bulletSpeed;

	this->color = { 0, 0, 255, 255 };
	this->damage = 4;

	this->id = weapon->id;

	this->SetLife(1.0f);

	this->health = 1;

	this->SetVelocity();
}


// Sets the bullet velocity direction
void Bullet::SetVelocity() {
	if (this->facing == Face::NORTH) this->dynamics.velocity.set(Axis::VERTICAL,	-this->speed);
	if (this->facing == Face::WEST) this->dynamics.velocity.set(Axis::HORIZONTAL,	-this->speed);
	if (this->facing == Face::SOUTH) this->dynamics.velocity.set(Axis::VERTICAL,	 this->speed);
	if (this->facing == Face::EAST) this->dynamics.velocity.set(Axis::HORIZONTAL,	 this->speed);
}



void Bullet::OnCollision() {
	this->Kill();
}


Bullet::~Bullet() {

}