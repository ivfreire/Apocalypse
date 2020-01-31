#include "zombie.h"

Zombie::Zombie(std::string title, Vector2 position) : Entity(title, position, { 50.0f, 50.0f }, EntityType::ZOMBIE) {
	this->color = { 255, 0, 0, 255 };
	this->speed = 50.0f;
}


void Zombie::WalkTo(Vector2 position, float tolerance) {
	Vector2 displacent = position;
	displacent.add(this->dynamics.position, -1.0f);
	if (displacent.module() > tolerance) {
		displacent = displacent.unit();
		displacent.scale(this->speed);
		this->dynamics.velocity = displacent;
	} else this->dynamics.velocity = { 0.0f, 0.0f };
}


Zombie::~Zombie() {

}