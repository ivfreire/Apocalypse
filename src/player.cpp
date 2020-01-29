#include "player.h"

Player::Player(std::string title, float x, float y, UserInterface* UI) : Entity(title, x, y, 50, 50, 0, EntityType::PLAYER) {
	this->UI = UI;

	this->weapon = new Weapon("USP", &this->dynamics.position, &this->size, &this->facing, 1, 1000.0f, 1, 0, 10, 10, 0.1f);
}


void Player::Update(float dtime) {
	this->Movement();
	this->weapon->Update(dtime);

	Entity::Update(dtime);
}

void Player::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_SPACE) this->weapon->isFiring = true;
	} else if (ev.type == SDL_KEYUP) {
		if (ev.key.keysym.sym == SDLK_SPACE) this->weapon->isFiring = false;
	}
}


void Player::Movement() {
	this->dynamics.velocity.set(Axis::HORIZONTAL, UI->GetAxis(Axis::HORIZONTAL, 0) * this->speed);
	this->dynamics.velocity.set(Axis::VERTICAL, UI->GetAxis(Axis::VERTICAL, 0) * this->speed);

	if (!this->weapon->isFiring) {
		if (UI->GetAxis(Axis::HORIZONTAL, 0) > 0) this->facing = Face::EAST;
		if (UI->GetAxis(Axis::HORIZONTAL, 0) < 0) this->facing = Face::WEST;
		if (UI->GetAxis(Axis::VERTICAL, 0) > 0) this->facing = Face::SOUTH;
		if (UI->GetAxis(Axis::VERTICAL, 0) < 0) this->facing = Face::NORTH;
	}
}


Player::~Player() {

}