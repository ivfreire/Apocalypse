#pragma once

#include "controller.h"
#include "world.h"

class Gameplay {
private:


public:
	World* world;


	Gameplay(Controller* ctrl);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	~Gameplay();

};