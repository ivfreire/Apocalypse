#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "userinterface.h"
#include "gameplay.h"
#include "entity.h"
#include "player.h"

enum class GameState { GAMEPLAY };

class Game {
private:
    int* width, * height;
    bool running;

    Uint32 now, before;
    float dtime;

    
    void CalculateFrameRate();


public:
    GameState state;

    UserInterface* UI;
    Gameplay* gameplay;


    Game(int* width, int* height);

    void Start();
    void Update();
    void Render(SDL_Renderer* rdr);
    void PollEvent(SDL_Event ev);

    float GetDeltaTime();
    void GameOver();

    bool IsOver();

    ~Game();

};