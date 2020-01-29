#include "zombie.h"

Zombie::Zombie(std::string title, float x, float y) : Entity(title, x, y, 50, 50, 0, EntityType::ZOMBIE) {
	this->speed = 100.0f;
}


void Zombie::WalkTo(Vector2 destination, float tolerance) {
	Vector2 displacement = destination; displacement.add(this->dynamics.position, -1.0f);
	Vector2 velocity = displacement.unit(); velocity.scale(this->speed);
	if (displacement.module() > tolerance) this->dynamics.velocity = velocity;
	else this->dynamics.velocity.set(0, 0);
}


Zombie::~Zombie() {

}