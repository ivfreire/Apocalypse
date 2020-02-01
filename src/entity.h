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

public:
	std::string title;
	SDL_Color color;

	Dynamics2 dynamics;
	Vector2 size;

	float speed;
	float mass;

	Face facing;
	EntityType type;

	int health;

	Collider* collider;


	Entity(std::string title, Vector2 position, Vector2 size, EntityType type);

	void Update(float dtime);
	void Render(SDL_Renderer* rdr, Vector2 camera);

	void TakeDamage(int damage);

	void SetLife(float time);
	void Kill();
	bool IsDead();

	~Entity();

};