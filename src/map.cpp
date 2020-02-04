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
	this->tilesets[0] = new Tileset(firstgid, ts_path);


	// Load layers
	for (int i = 0; i < MAX_LAYERS; i++) this->layers[i] = NULL;
	tinyxml2::XMLElement* layer = map->FirstChildElement("layer");
	std::string data(layer->FirstChildElement("data")->GetText());

	
}


void Map::Update(float dtime) {

}

void Map::Render(SDL_Renderer* rdr) {
	SDL_Rect rect = { 0, 0, 128, 128 };
	SDL_RenderCopy(rdr, this->tilesets[0]->texture, NULL, &rect);
}


Map::~Map() {

}