#include "player.h"

Player::Player(std::string title, Vector2 position, UserInterface* UI) : Entity(title, position, { 32.0f, 32.0f }, EntityType::PLAYER) {
	this->color = { 0, 0, 0, 255 };
	this->UI = UI;

	this->weapon = new Weapon("USP", &this->dynamics.position, &this->size, &this->facing, 10, 16, 1000.0f, 1.0f, 0.1f, 2.0f);
	this->weapon->id = 0;
	this->weapon->infinite = true;

	this->health = 4;
}


void Player::Update(float dtime) {
	this->Movement(dtime);
	this->SetFacing();
	this->weapon->Update(dtime);

	this->Regenerate(0.1f, dtime);

	Entity::Update(dtime);
}

void Player::PollEvent(SDL_Event ev) {
	if (ev.type  == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_SPACE) this->weapon->StartFiring();
	} else if (ev.type == SDL_KEYUP) {
		if (ev.key.keysym.sym == SDLK_SPACE) this->weapon->StopFiring();
	}
}

void Player::Movement(float dtime) {
	Vector2 velocity = UI->GetAxes(0);
	velocity.scale(this->speed);
	this->dynamics.velocity = velocity;
}

void Player::SetFacing() {
	if (!this->weapon->IsFiring()) {
		if (this->dynamics.velocity.get(Axis::VERTICAL)   < 0) this->facing = Face::NORTH;
		if (this->dynamics.velocity.get(Axis::HORIZONTAL) < 0) this->facing = Face::WEST;
		if (this->dynamics.velocity.get(Axis::VERTICAL)   > 0) this->facing = Face::SOUTH;
		if (this->dynamics.velocity.get(Axis::HORIZONTAL) > 0) this->facing = Face::EAST;
	}
}

void Player::TakeDamage(float damage) {
	Entity::TakeDamage(damage);
}

void Player::Regenerate(float rate, float dtime) {
	if (this->health < 4.0f && this->health > 0.0f) this->health += rate * dtime;
	if (this->health > 4.0f) this->health = 4.0f;
}

Player::~Player() {

}