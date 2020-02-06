#include "text.h"

Text::Text(Vector2* window, std::string text, TTF_Font* font, Vector2 position, SDL_Color color, SDL_Renderer* rdr) : Graph(window, position, { 0.0f, 0.0f }, color) {
	this->SetColor(color);

	this->SetSurface(TTF_RenderText_Solid(font, text.c_str(), color));
	this->SetTexture(SDL_CreateTextureFromSurface(rdr, this->GetSurface()));

	if (this->GetTexture() == NULL) std::cout << "Could not create texture from surface!" << std::endl;

	SDL_FreeSurface(this->GetSurface());

	this->image = true;
	this->fill = false;
	this->size = { (float)this->GetSurface()->w, (float)this->GetSurface()->h };
}


void Text::SetText(std::string text, TTF_Font* font, SDL_Renderer* rdr) {
	this->SetSurface(TTF_RenderText_Solid(font, text.c_str(), this->color));
	this->SetTexture(SDL_CreateTextureFromSurface(rdr, this->GetSurface()));
	if (this->GetTexture() == NULL) std::cout << "Could not create texture f]rom surface!" << std::endl;
	SDL_FreeSurface(this->GetSurface());
}


Text::~Text() {

}