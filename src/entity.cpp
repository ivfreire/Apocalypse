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

	this->lifetime = 0.0f;
	this->life = this->lifetime;

	this->collider = new Collider(&this->dynamics.position, &this->size);
}


void Entity::Update(float dtime) {
	if (this->life > 0.0f) this->life -= dtime;
	if (this->life <= 0.0f && this->lifetime > 0.0f) this->Kill();

	this->dynamics.velocity.add(this->dynamics.acceleration, dtime);
	this->dynamics.position.add(this->dynamics.velocity, dtime);

	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };

	this->collider->Update(dtime);
}

void Entity::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(rdr, &this->rect);
	this->collider->Render(rdr);
}


void Entity::SetLife(float time) {
	this->lifetime = time;
	this->life = this->lifetime;
}

void Entity::Kill() { this->destroy = true; }
bool Entity::IsDead() { return this->destroy; };


Entity::~Entity() {

}