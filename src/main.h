#pragma once

#include <iostream>
#include <thread>
#include <SDL2/SDL.h>
#include "engine.h"
#include "controller.h"
#include "game.h"

#define MAX_THREADS	8

int main(int argc, char* argv[]);

// THREAD FUNCTIONS
void Update(Game* game);
void Render(Game* game);
void PollEvent(Game* game);