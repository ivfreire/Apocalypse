#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "engine.h"
#include "collider.h"

enum class EntityType { PLAYER, ZOMBIE, BULLET };
enum class Face { NORTH, WEST, SOUTH, EAST };

class Entity {
private:
	SDL_Rect rect;
	SDL_Color color;
	float life;
	bool dead;

public:
	std::string title;
	EntityType type;

	Dynamics2 dynamics;
	Vector2 size;
	Collider* collider;

	Face facing;

	float speed = 200;

	float lifetime;


	Entity(std::string title, float x, float y, float width, float height, float lifetime, EntityType type);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	bool IsDead();

	~Entity();

};