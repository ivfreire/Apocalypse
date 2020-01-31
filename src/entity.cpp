#include "entity.h"

Entity::Entity(std::string title, Vector2 position, Vector2 size, EntityType type) {
	this->title = title;
	
	this->dynamics.position = position;
	this->dynamics.velocity = { 0.0f, 0.0f };
	this->dynamics.acceleration = { 0.0f, 0.0f };

	this->size = size;
	this->type = type;

	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };
	this->color = { 0, 0, 0, 255};

	this->facing = Face::SOUTH;
	this->speed = 200.0f;

	this->mass = 1.0f;
}


void Entity::Update(float dtime) {
	this->dynamics.velocity.add(this->dynamics.acceleration, dtime);
	this->dynamics.position.add(this->dynamics.velocity, dtime);

	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };
}

void Entity::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(rdr, &this->rect);
}


Entity::~Entity() {

}