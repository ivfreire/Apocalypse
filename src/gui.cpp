#include "gui.h"

GUI::GUI(Vector2* window) {
	this->window = window;
	this->current = -1;
	for (int i = 0; i < MAX_SCREENS; i++) this->screens[i] = NULL;
}


void GUI::Update(float dtime) {
	if (this->current != -1) this->screens[current]->Update(dtime);
}

void GUI::Render(SDL_Renderer* rdr) {
	if (this->current != -1) this->screens[current]->Render(rdr);
}


void GUI::AddScreen(Screen* screen) {
	bool found = false;
	for (int i = 0; i < MAX_SCREENS && !found; i++) if (this->screens[i] == NULL) {
		this->screens[i] = screen;
		found = true;
	}
}


GUI::~GUI() {

}