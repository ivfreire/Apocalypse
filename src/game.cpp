#include "game.h"

Game::Game(int* width, int* height) {
    this->width = width;
    this->height = height;

    this->running = true;

    this->UI = new UserInterface();
    
    this->gameplay = new Gameplay(this->UI);
    this->gameplay->SetWindowSize(width, height);
}


void Game::Start() {
    this->gameplay->Start();
}

void Game::Update() {
    this->gameplay->Update(this->GetDeltaTime());
    this->CalculateFrameRate();
}

void Game::Render(SDL_Renderer* rdr) {
    this->gameplay->Render(rdr);
}

void Game::PollEvent(SDL_Event ev) {
    this->UI->PollEvent(ev);
    this->gameplay->PollEvent(ev);
    if (ev.type == SDL_KEYDOWN) if (ev.key.keysym.sym == SDLK_ESCAPE) this->running = false;
}


// Gets the delta time between frames
float Game::GetDeltaTime() {
    return this->dtime;
}

void Game::GameOver() {
    this->running = false;
}

// Checks is the game has been killed
bool Game::IsOver() {
    return !this->running;
}



// PRIVATE METHODS


void Game::CalculateFrameRate() {
    this->now = SDL_GetTicks();
    Uint32 dtick = this->now - this->before;
    this->before = this->now;
    this->dtime = float(dtick)/1000.0f;
    if (this->dtime > 1.0f) this->dtime = 1.0f;
}


Game::~Game() {
    this->gameplay->~Gameplay();
}