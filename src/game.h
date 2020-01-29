#pragma once

#include <SDL2/SDL.h>
#include "engine.h"
#include "controller.h"
#include "gameplay.h"

class Game {
private:
	Controller* ctrl;
	bool running;

	SDL_Renderer* rdr;

public:
	Gameplay* gameplay;


	Game(Controller* ctrl);

	void Start();
	void Update();
	void Render();
	void PollEvent(SDL_Event ev);

	void GameOver();
	bool IsOver();

	~Game();

};