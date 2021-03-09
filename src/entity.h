#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "engine.h"
#include "collider.h"

enum class EntityType { PLAYER, ZOMBIE, BULLET };
enum class Face { NORTH, WEST, SOUTH, EAST };

class Entity {
private:
	SDL_Rect rect;

	bool destroy;
	float life, lifetime;

	SDL_Texture* texture;
	SDL_Rect tileset_rect;

public:
	bool image, fill;

	std::string title;
	SDL_Color color;

	Dynamics2 dynamics;
	Vector2 size;

	float speed;
	float mass;

	Face facing;
	EntityType type;

	float health;

	Collider* collider;

	Int2 square;


	Entity(std::string title, Vector2 position, Vector2 size, EntityType type);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr, Vector2 camera);

	void TakeDamage(float damage);
	void SetPosition(Vector2 position);

	void SetTexture(SDL_Texture* texture);
	void SetTileset(SDL_Texture* texture, SDL_Rect rect);
	void SetLife(float time);
	void Kill();
	bool IsDead();

	~Entity();

};