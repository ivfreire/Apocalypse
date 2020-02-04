#pragma once

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "controller.h"
#include "entity.h"
#include "player.h"
#include "zombie.h"
#include "bullet.h"
#include "camera.h"
#include "map.h"

#define MAX_ZOMBIES	64
#define MAX_BULLETS 128
#define MAX_PLAYERS	4

class World {
private:
	Controller* ctrl;
	int totalZombies, spawnedZombies;
	int round;

	SDL_Rect frontiers;

public:
	Vector2 size, tilesize;
	Map* map;

	Camera* camera;

	Player* player;
	Zombie* zombies[MAX_ZOMBIES];
	Bullet* bullets[MAX_BULLETS];

	int kills;


	World(Controller* ctrl, std::string path);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void InitPlayers(int money);
	bool IsPlayerDead();

	void PlayerFire();
	void SpawnBullet(Weapon* weapon);
	void SpawnZombies(int population);
	void SpawnMissingZombies(int index);
	void CheckCollisions();
	void KeepPlayerIn(Dynamics2* dynamics, Vector2 size);

	void NewRound(int zombies, int round);
	Zombie* RoundZombie(int round);

	~World();

};



/*


HASH-MAPS

Entity* hashmap[ZOMBIES + BULLETS + ITEMS][ZOMBIES + BULLETS + ITEMS];


*/