#include "screen.h"

Screen::Screen(Vector2* window) {
	this->window = window;
}


void Screen::Update(float dtime) {
	for (Graph* graph : graphs) graph->Update(dtime);
}

void Screen::Render(SDL_Renderer* rdr) {
	for (Graph* graph : graphs) graph->Render(rdr);
}


void Screen::LoadFont(std::string path, int size) {
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	if (font) this->fonts.push_back(TTF_OpenFont(path.c_str(), size));
	else std::cerr << "Could not load font!" << std::endl;
}


Screen::~Screen() {

}