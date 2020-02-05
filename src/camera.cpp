#include "camera.h"

Camera::Camera(std::string title, Vector2 position, Vector2* screen) {
	this->title = title;
	this->position = position;
	this->screen = screen;

	this->scale = { 50.0f / 32.0f, 50.0f / 32.0f };
}


void Camera::CenterAt(Vector2 position) {
	this->position.x = position.x - (this->screen->x / 2) / this->scale.x;
	this->position.y = position.y - (this->screen->y / 2) / this->scale.y;
}


Camera::~Camera() {

}