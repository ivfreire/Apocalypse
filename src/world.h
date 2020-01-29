#pragma once
#include <SDL2/SDL.h>

class World {
private:


public:
	World();

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	~World();

};