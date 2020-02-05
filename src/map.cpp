#include "map.h"

Map::Map(std::string path) {

	tinyxml2::XMLDocument doc;
	doc.LoadFile(path.c_str());

	// Loads basics of the world
	tinyxml2::XMLElement* map = doc.FirstChildElement("map");
	this->width = atoi(map->FindAttribute("width")->Value());
	this->height = atoi(map->FindAttribute("height")->Value());
	this->tilewidth = atoi(map->FindAttribute("tilewidth")->Value());
	this->tileheight = atoi(map->FindAttribute("tileheight")->Value());


	// Loads tilesets
	tinyxml2::XMLElement* tileset = map->FirstChildElement("tileset");
	int firstgid = atoi(tileset->FindAttribute("firstgid")->Value());
	std::string ts_path(tileset->FindAttribute("source")->Value());
	this->tilesets.push_back(new Tileset(firstgid, ts_path));


	// Load layers
	tinyxml2::XMLElement* layer = map->FirstChildElement("layer");
	int id = atoi(layer->FindAttribute("id")->Value());
	std::string name(layer->FindAttribute("name")->Value());
	int layer_width = atoi(layer->FindAttribute("width")->Value());
	int layer_height = atoi(layer->FindAttribute("height")->Value());
	std::string layer_data(layer->FirstChildElement("data")->GetText());
	Layer _layer = { id, name, layer_width, layer_height };
	_layer.rect = { 0, 0, (int)(layer_width * this->tilewidth), (int)(layer_height * this->tileheight) };

	std::vector<std::string> data = this->SplitString(layer_data, ',');
	for (std::string tile : data) _layer.data.push_back(atoi(tile.c_str()));

	this->layers.push_back(_layer);
}


void Map::Update(float dtime) {

}

void Map::Render(SDL_Renderer* rdr, Vector2 camera) {
	for (Layer layer : this->layers) {
		SDL_Rect new_rect = layer.rect;
		new_rect.x = -camera.x;
		new_rect.y = -camera.y;
		SDL_RenderCopy(rdr, this->layers.at(0).texture, NULL, &new_rect);
	}
}


void Map::RenderLayers(SDL_Renderer* rdr) {
	for (unsigned int x = 0; x < this->layers.capacity(); x++) {
		Layer* layer = &this->layers.at(x);
		SDL_Surface* surface = SDL_CreateRGBSurface(0, layer->width * this->tilewidth, layer->height * this->tileheight, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);

		for (unsigned int i = 0; i < layer->data.capacity(); i++) if (layer->data.at(i) != 0) {
			SDL_Rect destiny = { (int)((i % this->width) * this->tilewidth), (int)(i / this->width) * this->tileheight, this->tilewidth, this->tileheight };
			SDL_BlitSurface(this->GetTile(layer->data.at(i)), NULL, surface, &destiny);
		}

		layer->texture = SDL_CreateTextureFromSurface(rdr, surface);
		SDL_FreeSurface(surface);
	}
}





std::vector<std::string> Map::SplitString(std::string input, char pattern) {
	std::vector<std::string> words;
	std::string word;

	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.at(i) == pattern) {
			words.push_back(word);
			word.clear();
		} else word.push_back(input.at(i));
	}
	words.push_back(word);

	return words;
}

SDL_Surface* Map::GetTile(int id) {
	return this->tilesets.at(0)->GetTile(id);
}


Map::~Map() {

}