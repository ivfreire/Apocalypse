#include "graph.h"

Graph::Graph() {
	this->centered = false;
}


void Graph::Update(float dtime) {
	// this->rect = { (int)this->position.x, (int)this->position.y, (int)this->size.x, (int)this->size.y };
}

void Graph::Render(SDL_Renderer* rdr) {
	if (texture) SDL_RenderCopy(rdr, this->texture, NULL, &this->rect);
}


void Graph::SetColor(SDL_Color color) { this->color = color; }
void Graph::SetSurface(SDL_Surface* surface) { this->surface = surface; }
void Graph::SetTexture(SDL_Texture* texture) { this->texture = texture; }
SDL_Color Graph::GetColor() { return this->color; };
SDL_Surface* Graph::GetSurface() { return this->surface; };


Graph::~Graph() {
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);
}