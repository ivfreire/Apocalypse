#include "player.h"

Player::Player(std::string title, Vector2 position) : Entity(title, position, { 50.0f, 50.0f }, EntityType::PLAYER) {
	this->color = { 0, 0, 0, 255 };
}

Player::~Player() {

}