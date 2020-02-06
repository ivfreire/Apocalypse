#include "gui.h"

GUI::GUI(Vector2* window) {
	this->window = window;
	this->current = -1;
}


void GUI::Update(float dtime) {
	if (this->current != -1) this->screens[current]->Update(dtime);
}

void GUI::Render(SDL_Renderer* rdr) {
	if (this->current != -1) this->screens[current]->Render(rdr);
}


void GUI::AddScreen(Screen* screen) {
	this->screens.push_back(screen);
}


GUI::~GUI() {

}