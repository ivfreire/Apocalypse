#pragma once

#include "controller.h"
#include "world.h"
#include "screen.h"
#include "text.h"

#define MAX_PLAYERS	4

enum class GameplayState { PLAYING, PAUSED, GAMEOVER };

class Gameplay {
private:
	Controller* ctrl;
	bool lockEscape;

	SDL_Rect background;

public:
	World* world;

	int round;
	int* current;

	Screen* menu;
	GameplayState state;


	Gameplay(Controller* ctrl);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void RoundControl();
	void NewRound();
	int ZombiesSpawnNumber(int round);

	~Gameplay();

};