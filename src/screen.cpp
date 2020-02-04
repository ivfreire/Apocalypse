#include "screen.h"

Screen::Screen(Vector2* window) {
	this->window = window;
	for (int i = 0; i < MAX_GRAPHS; i++) this->graphs[i] = NULL;
	for (int i = 0; i < MAX_FONTS; i++) this->fonts[i] = NULL;
}


void Screen::Update(float dtime) {
	for (int i = 0; i < MAX_GRAPHS; i++) if (this->graphs[i]) this->graphs[i]->Update(dtime);
}

void Screen::Render(SDL_Renderer* rdr) {
	for (int i = 0; i < MAX_GRAPHS; i++) if (this->graphs[i]) {
		if (this->graphs[i]->centered) this->graphs[i]->position.x = (int)((this->window->x - this->graphs[i]->rect.w) / 2);
		this->graphs[i]->Render(rdr);
	}
}


void Screen::LoadFont(std::string path, int size) {
	bool found = false;
	for (int i = 0; i < MAX_FONTS && !found; i++) if (this->fonts[i] == NULL) {
		this->fonts[i] = TTF_OpenFont(path.c_str(), size);
		found = true;
	}
}


Screen::~Screen() {

}