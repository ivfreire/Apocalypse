#include "main.h"

int main(int argc, char* argv[]) {
    // Initializes SDL2.0
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL2 was not initialized!" << std::endl;
        return -1;
    }


    // Instanciates global variables
    int width = 1900, height = 1000;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Game* game;


    // Define global variables
    window = SDL_CreateWindow(
        "Apocalypse",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        std::cerr << "Windown could not be created!" << std::endl;
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Renderer could not be created!" << std::endl;
        return -1;
    } else SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


    game = new Game(&width, &height);

    game->Start();


    // Creates global threads
    std::thread threads[MAX_THREADS];

    // Instanciates threads
    threads[0] = std::thread(Update, game);
    threads[1] = std::thread(Render, renderer, game);
    threads[2] = std::thread(PollEvent, game);

    for (int i = 0; i < MAX_THREADS; i++) threads[i].join();


    // Destroys instances and free up memory
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    SDL_Quit();
    return 0;
}





// THREADS FUNCTIONS

void Update(Game* game) {
    while (!game->IsOver()) game->Update();
}

void Render(SDL_Renderer* renderer, Game* game) {
    while (!game->IsOver()) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        game->Render(renderer);
        SDL_RenderPresent(renderer);
    }
}

void PollEvent(Game* game) {
    while (!game->IsOver()) {
        SDL_Event ev;
        SDL_PollEvent(&ev);
        if (ev.type == SDL_QUIT) game->GameOver();
        game->PollEvent(ev);
    }
}