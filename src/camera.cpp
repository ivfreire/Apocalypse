#include "camera.h"

Camera::Camera(std::string title, Vector2 position, Vector2* screen) {
	this->title = title;
	this->position = position;
	this->screen = screen;

}


void Camera::CenterAt(Vector2 position) {
	this->position.x = position.x - (this->screen->x / 2);
	this->position.y = position.y - (this->screen->y / 2);
}


Camera::~Camera() {

}