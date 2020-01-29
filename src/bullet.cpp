#include "bullet.h"

Bullet::Bullet(Vector2 position, Face facing, float speed, float lifetime) : Entity("Bullet", position.x, position.y, 10, 10, lifetime, EntityType::BULLET) {
	this->facing = facing;
	this->speed = speed;

	if (this->facing == Face::NORTH) this->dynamics.velocity.set(Axis::VERTICAL, -this->speed);
	if (this->facing == Face::WEST) this->dynamics.velocity.set(Axis::HORIZONTAL, -this->speed);
	if (this->facing == Face::SOUTH) this->dynamics.velocity.set(Axis::VERTICAL, this->speed);
	if (this->facing == Face::EAST) this->dynamics.velocity.set(Axis::HORIZONTAL, this->speed);
}

Bullet::~Bullet() {

}