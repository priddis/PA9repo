//not much needed for this class. this is an abstract class. derived classes will be used for specific terrain tiles.
//no setimpedence defined because it is virtual
//tw 4/18/18

#include "header/Terrain.h"


Terrain::Terrain(sf::Texture*& in_texture, float in_scale)
	: sf::Sprite(*in_texture)
{
	this->setScale(in_scale, in_scale);
}

Terrain::~Terrain() {}

std::string Terrain::getTerrainType() {
	return terrainType;
}

bool Terrain::getTraversable() {
	return traversable;
}

void Terrain::setTerrainType(std::string in_terrainType) {
	terrainType = in_terrainType;
}

void Terrain::setTraversable(bool in_traversable) {
	traversable = in_traversable;
}
