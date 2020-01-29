#pragma once
#include <SDL2/SDL.h>
#include "engine.h"

#define MAX_AXES    8

class UserInterface {
private:


public:
    Vector2 axes[MAX_AXES];


    UserInterface();

    void PollEvent(SDL_Event ev);

    void Keyboard(SDL_Event ev);

    float GetAxis(Axis axis, int id);

    ~UserInterface();

};

/*


    Input.GetAxis("Horizontal");

    UI->GetAxis(Axis::HORIZONTAL);


*/