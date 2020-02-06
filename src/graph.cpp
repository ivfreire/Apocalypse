#include "graph.h"

Graph::Graph(Vector2* window, Vector2 position, Vector2 size, SDL_Color color) {
	this->window = window;

	this->position = position;
	this->size = size;
	this->color = color;

	this->relative.position = { 0.0f, 0.0f };
	this->relative.size = { 0.0f, 0.0f };

	this->fill = true;
	this->outline = false;
	this->image = false;

	this->rect = { (int)(position.x * window->x), (int)(position.y * window->y), (int)(size.x * window->x), (int)(size.y * window->y) };
}


void Graph::Update(float dtime) {
	this->rect = {
		(int)(this->relative.position.x * this->window->x + this->position.x),
		(int)(this->relative.position.y * this->window->y + this->position.y),
		(int)(this->relative.size.x * this->window->x + this->size.x),
		(int)(this->relative.size.y * this->window->y + this->size.y)
	};
}

void Graph::Render(SDL_Renderer* rdr) {
	if (this->fill) {
		SDL_SetRenderDrawColor(rdr, this->color.r, this->color.g, this->color.b, this->color.a);
		SDL_RenderFillRect(rdr, &this->rect);
	}
	if (this->outline) {
		SDL_SetRenderDrawColor(rdr, this->outline_color.r, this->outline_color.g, this->outline_color.b, this->outline_color.a);
		SDL_RenderDrawRect(rdr, &this->rect);
	}
	if (this->image) SDL_RenderCopy(rdr, this->texture, NULL, &this->rect);
}


void Graph::SetColor(SDL_Color color) { this->color = color; }
void Graph::SetSurface(SDL_Surface* surface) { this->surface = surface; }
void Graph::SetTexture(SDL_Texture* texture) { this->texture = texture; }
SDL_Color Graph::GetColor() { return this->color; };
SDL_Surface* Graph::GetSurface() { return this->surface; };
SDL_Texture* Graph::GetTexture() { return this->texture; };


Graph::~Graph() {
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);
}