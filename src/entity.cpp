#include "entity.h"

Entity::Entity(std::string title, float x, float y, float width, float height, float lifetime, EntityType type) {
	this->title = title;

	this->dynamics.position.set(x, y);
	this->size.set(width, height);

	this->dynamics.acceleration.set(0, 0);
	this->dynamics.velocity.set(0, 0);

	this->type = type;

	if (type == EntityType::PLAYER) this->color = {   0,   0,   0, 255 };
	if (type == EntityType::ZOMBIE) this->color = { 255,   0,   0, 255 };
	if (type == EntityType::BULLET) this->color = {   0,   0, 255, 255 };

	this->facing = Face::SOUTH;

	this->lifetime = lifetime;
	this->life = this->lifetime;
	this->dead = false;

	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };

	this->collider = new Collider(this->title, ColliderShape::BOX, &this->dynamics.position, &this->size);
}


void Entity::Start() {

}

void Entity::Update(float dtime) {
	if (this->lifetime > 0.0f) this->life -= dtime;
	if (this->life < 0.0f) this->dead = true;

	this->dynamics.velocity.add(this->dynamics.acceleration, dtime);
	this->dynamics.position.add(this->dynamics.velocity, dtime);
	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };

	this->collider->Update();
}

void Entity::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(rdr, &rect);
	this->collider->Render(rdr);
}


// Checks if the entity has expired
bool Entity::IsDead() {
	return this->dead;
}


Entity::~Entity() {

}