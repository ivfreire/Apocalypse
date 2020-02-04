#include "text.h"

Text::Text(std::string text, TTF_Font* font, SDL_Color color, SDL_Renderer* rdr) {
	this->SetColor(color);

	this->SetSurface(TTF_RenderText_Solid(font, text.c_str(), color));
	this->SetTexture(SDL_CreateTextureFromSurface(rdr, this->GetSurface()));

	this->position = { 0.0f, 0.0f };
	this->size = { (float)this->GetSurface()->w, (float)this->GetSurface()->h };
}


Text::~Text() {

}