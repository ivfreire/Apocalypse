#pragma once

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <SDL2/SDL.h>
#include "controller.h"
#include "entity.h"
#include "player.h"
#include "zombie.h"
#include "bullet.h"

#define MAX_ZOMBIES	64
#define MAX_BULLETS 128

class World {
private:
	Controller* ctrl;

public:
	Player* player;

	Zombie* zombies[MAX_ZOMBIES];
	Bullet* bullets[MAX_BULLETS];



	World(Controller* ctrl);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void PlayerFire();
	void SpawnBullet(Weapon* weapon);
	void SpawnZombies(int population);

	~World();

};