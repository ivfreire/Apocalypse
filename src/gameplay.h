#pragma once
#include <SDL2/SDL.h>
#include "userinterface.h"
#include "world.h"

enum class GameplayState { PLAYING, PAUSED };

class Gameplay {
private:
	UserInterface* UI;
	int* width, * height;

	SDL_Rect background;
	float buffer;


public:
	GameplayState state;

	World* world;


	Gameplay(UserInterface* UI);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void SetWindowSize(int* width, int* height);

	bool IsPaused();

	~Gameplay();

};
