#pragma once
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include "userinterface.h"
#include "entity.h"
#include "player.h"
#include "zombie.h"
#include "bullet.h"

#define MAX_ZOMBIES	64
#define MAX_BULLETS	64

class World {
private:
	UserInterface* UI;
	int* width, * height;

public:
	Player* player;

	Zombie* zombies[MAX_ZOMBIES];
	Bullet* bullets[MAX_BULLETS];


	World(UserInterface* UI);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void SpawnZombies(int population);
	void PlayerFire();

	void SetWindowSize(int* width, int* height);

	~World();

};