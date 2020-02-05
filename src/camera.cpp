#include "camera.h"

Camera::Camera(std::string title, Vector2 position, Vector2* screen) {
	this->title = title;
	this->position = position;
	this->screen = screen;

	this->scale = { 50.0f / 32.0f, 50.0f / 32.0f };
}


void Camera::CenterAt(Vector2 position, Vector2 world_size) {
	if (position.x > (screen->x / 2) / this->scale.x && position.x < world_size.x - (screen->x / 2) / this->scale.x) this->position.x = position.x - (this->screen->x / 2) / this->scale.x;
	else if (position.x < screen->x / 2) this->position.x = 0;
	else if (position.x > world_size.x - (screen->x / 2) / this->scale.x) this->position.x = world_size.x - screen->x / this->scale.x;
	if (position.y > (screen->y / 2) / this->scale.y && position.y < world_size.y - (screen->y / 2) / this->scale.y) this->position.y = position.y - (this->screen->y / 2) / this->scale.y;
	else if (position.y < screen->y / 2) this->position.y = 0;
	else if (position.y > world_size.y - (screen->y / 2) / this->scale.y) this->position.y = world_size.y - screen->y / this->scale.y;
}


Camera::~Camera() {

}