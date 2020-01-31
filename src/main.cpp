#include "main.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
		std::cout << "Could not load SDL2!" << std::endl;
		return -1;
	}



	// Instanciates global variables
	Controller* controller;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game* game;



	// Defines global variables
	controller = new Controller(640, 480);

	window = SDL_CreateWindow(
		"Apocalypse",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		controller->window.x, controller->window.y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	if (!window) {
		std::cout << "Could not create window!" << std::endl;
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "Could not create renderer!" << std::endl;
		return -1;
	}
	controller->screen = window;
	controller->renderer = renderer;

	game = new Game(controller);





	game->Start();

	// THREADS
	std::thread threads[MAX_THREADS];
	threads[0] = std::thread(Update, game);
	threads[1] = std::thread(Render, game);
	threads[2] = std::thread(PollEvent, game);

	for (int i = 0; i < MAX_THREADS; i++) threads[i].join();


	// Free up space
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);


	SDL_Quit();
	return 0;
}






void Update(Game* game) {
	while (!game->IsOver()) game->Update();
}

void Render(Game* game) {
	while (!game->IsOver()) game->Render();
}

void PollEvent(Game* game) {
	while (!game->IsOver()) {
		SDL_Event ev;
		SDL_PollEvent(&ev);
		game->PollEvent(ev);
		if (ev.type == SDL_QUIT) game->GameOver();
	}
}