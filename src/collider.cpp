#include "collider.h"

Collider::Collider(std::string title, ColliderShape shape, Vector2* position, Vector2* size) {
	this->title = title;
	this->shape = shape;
	this->position = position;
	this->size = size;
}


void Collider::Update() {
	this->rect = { (int)this->position->x, (int)this->position->y, (int)this->size->x, (int)this->size->y };
}

void Collider::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
	SDL_RenderDrawRect(rdr, &this->rect);
}

Collider::~Collider() {

}