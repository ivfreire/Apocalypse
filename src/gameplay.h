#pragma once

#include "controller.h"
#include "world.h"

enum class GameplayState { PLAYING, PAUSED };

class Gameplay {
private:
	Controller* ctrl;
	bool lockEscape;

	SDL_Rect background;

public:
	World* world;

	GameplayState state;


	Gameplay(Controller* ctrl);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	~Gameplay();

};