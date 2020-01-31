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

#define MAX_ZOMBIES	64

class World {
private:
	Controller* ctrl;

public:
	Player* player;

	Zombie* zombies[MAX_ZOMBIES];


	World(Controller* ctrl);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void SpawnZombies(int population);

	~World();

};