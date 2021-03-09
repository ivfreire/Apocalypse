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

	this->health = 10;

	this->destroy = false;

	this->image = false;
	this->fill = true;
}

void Entity::Update(float dtime) {
	if (this->life > 0.0f) this->life -= dtime;
	if (this->life <= 0.0f && this->lifetime > 0.0f) this->Kill();

	this->dynamics.velocity.add(this->dynamics.acceleration, dtime);
	this->dynamics.position.add(this->dynamics.velocity, dtime);

	this->dynamics.acceleration = { 0.0f, 0.0f };

	this->rect = { (int)this->dynamics.position.x, (int)this->dynamics.position.y, (int)this->size.x, (int)this->size.y };

	if (this->health <= 0) this->Kill();

	this->square = { (int)this->dynamics.position.x % 100, (int)this->dynamics.position.y % 100 };

	this->collider->Update(dtime);
}

void Entity::Render(SDL_Renderer* rdr, Vector2 camera) {
	SDL_SetRenderDrawColor(rdr, this->color.r, this->color.g, this->color.b, this->color.a);

	SDL_Rect new_rect = { (int)(this->rect.x - camera.x), (int)(this->rect.y - camera.y), this->rect.w, this->rect.h };

	// this->collider->SetRect(new_rect);
	if (this->fill) SDL_RenderFillRect(rdr, &new_rect);
	if (this->image) SDL_RenderCopy(rdr, this->texture, &this->tileset_rect, &new_rect);

	// this->collider->Render(rdr);
}

void Entity::TakeDamage(float damage) {
	this->health -= damage;
}

void Entity::SetPosition(Vector2 position) { this->dynamics.position = position; }

void Entity::SetTexture(SDL_Texture* texture) {
	this->texture = texture;
	this->fill = false;
	this->image = true;
}

void Entity::SetTileset(SDL_Texture* texture, SDL_Rect rect) {
	this->SetTexture(texture);
	this->tileset_rect = rect;
}

void Entity::SetLife(float time) {
	this->lifetime = time;
	this->life = this->lifetime;
}

void Entity::Kill() { this->destroy = true; }
bool Entity::IsDead() { return this->destroy; };

Entity::~Entity() {

}