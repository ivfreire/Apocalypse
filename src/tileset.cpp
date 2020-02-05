#include "tileset.h"

Tileset::Tileset(int firstgid, std::string path) {
	this->firstgid = firstgid;

	tinyxml2::XMLDocument doc;
	doc.LoadFile(path.c_str());

	tinyxml2::XMLElement* tileset = doc.FirstChildElement("tileset");
	this->name = tileset->FindAttribute("name")->Value();
	this->tilewidth = atoi(tileset->FindAttribute("tilewidth")->Value());
	this->tileheight = atoi(tileset->FindAttribute("tileheight")->Value());
	this->tilecount = atoi(tileset->FindAttribute("tilecount")->Value());
	this->columns = atoi(tileset->FindAttribute("columns")->Value());


	tinyxml2::XMLElement* image = tileset->FirstChildElement("image");
	std::string img_path(image->FindAttribute("source")->Value());
	this->surface = IMG_Load(img_path.c_str());
	if (this->surface == NULL) std::cerr << "Could not load image!" << std::endl;

	for (int i = 0; i < this->tilecount; i++) {
		SDL_Rect source = { (i % this->columns) * this->tilewidth, (int)(i / this->columns) * this->tileheight, this->tilewidth, this->tileheight };
		this->tiles.push_back(SDL_CreateRGBSurface(0, this->tilewidth, this->tileheight, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff));
		SDL_BlitSurface(this->surface, &source, this->tiles.at(i), NULL);
	}
}


SDL_Surface* Tileset::GetTile(int id) {
	if (id > 0) return this->tiles.at(id - this->firstgid);
	return NULL;
}


Tileset::~Tileset() {

}