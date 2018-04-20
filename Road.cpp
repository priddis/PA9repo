//not much needed for this class. derived from terrain
//road is the only terrain tile with a negative impedence (units will go faster!)
//tw 4/18/18

#include "header/Road.h"

Road::Road(sf::Texture* in_texture, float in_scale)
	: Terrain(in_texture, in_scale)
{}

Road::~Road() {}

void Road::setImpedence(int in_impedence) {
	//this will be the only example of a negative impedence.. because a road will make them travel faster while any others will either be neutral (0) or a pos impedence
	impedence = -1;
}