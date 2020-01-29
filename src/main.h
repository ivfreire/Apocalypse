#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <SDL2/SDL.h>
#include "game.h"

#define MAX_THREADS	8

int main(int argc, char* argv[]);

// Threads functions
void Update(Game* game);
void Render(SDL_Renderer* rdr, Game* game);
void PollEvent(Game* game);