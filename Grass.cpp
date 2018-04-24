
#include "header/Grass.h"


Grass::Grass(sf::Texture* in_texture, float in_scale)
	: Terrain(in_texture, in_scale)
{
}

Grass::~Grass() {}

void Grass::setImpedence(int in_impedence) {
	//this will be the only example of a negative impedence.. because a road will make them travel faster while any others will either be neutral (0) or a pos impedence
	impedence = 0;
}