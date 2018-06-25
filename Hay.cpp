#include "header/Hay.h"

Hay::Hay(sf::Texture* in_texture, float in_scale) : Terrain(in_texture, in_scale)
{
	setTerrainType("Hay");
	setTraversable(false);

}

Hay::~Hay() {}

