#include "main.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
		std::cout << "Could not load SDL2!" << std::endl;
		return -1;
	}
	if (TTF_Init() != 0) {
		std::cout << "Could not load TTF library of SDL2!" << std::endl;
		return -1;
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
		std::cout << "Could not load SDL_image library of SDL2!" << std::endl;
		return -1;
	}


	// Instanciates global variables
	Controller* controller;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game* game;



	// Defines global variables
	controller = new Controller(800, 600);

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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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
	// threads[3] = std::thread(Command, game);

	for (int i = 0; i < MAX_THREADS; i++) threads[i].join();


	// Free up space
	game->~Game();
	controller->~Controller();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);


	IMG_Quit();
	TTF_Quit();
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

void Command(Game* game) {
	while (!game->IsOver()) {
		std::string command;
		std::cout << ">>>: ";
		std::cin >> command;
		if (command == "exit") game->GameOver();
		if (command == "pause") game->gameplay->state = GameplayState::PAUSED;
		if (command == "play") game->gameplay->state = GameplayState::PLAYING;
	}
}