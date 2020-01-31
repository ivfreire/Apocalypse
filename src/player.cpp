#include "player.h"

Player::Player(std::string title, Vector2 position, UserInterface* UI) : Entity(title, position, { 50.0f, 50.0f }, EntityType::PLAYER) {
	this->color = { 0, 0, 0, 255 };
	this->UI = UI;
}


void Player::Update(float dtime) {
	this->Movement(dtime);
	Entity::Update(dtime);
}


void Player::Movement(float dtime) {
	Vector2 velocity = UI->GetAxes(0);
	velocity.scale(this->speed);
	this->dynamics.velocity = velocity;
}


Player::~Player() {

}