#include "collider.h"

Collider::Collider(Vector2* position, Vector2* size) {
	this->position = position;
	this->size = size;
}


void Collider::Update(float dtime) {
	this->rect = { (int)this->position->x, (int)this->position->y, (int)this->size->x, (int)this->size->y };
}

void Collider::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
	SDL_RenderDrawRect(rdr, &this->rect);
}


bool Collider::CheckCollision(Collider* other) {
	float radius = (this->size->x + this->size->y) / 4;
	float otherRadius = (other->size->x + other->size->y) / 4;

	Vector2 distance = *other->position;
	distance.add(*other->size, 0.5f);
	distance.add(*this->position, -1.0f);
	distance.add(*this->size, -0.5f);

	if (distance.module() <= (radius + otherRadius)) return true;
	else return false;
}


void Collider::SetRect(SDL_Rect rect) {
	this->rect = rect;
}


Collider::~Collider() {

}