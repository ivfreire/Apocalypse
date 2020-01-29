#pragma once

#include <SDL2/SDL.h>
#include "entity.h"
#include "player.h"

class World {
private:


public:
	Player* player;


	World();

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	~World();

};