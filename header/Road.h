//not much needed for this class. derived from terrain
//road is the only terrain tile with a negative impedence (units will go faster!)
//this is the only concrete terrain defined thus far
//tw 4/18/18

#pragma once
#include "Terrain.h"

class Road :
	public Terrain
{
public:
	Road(sf::Texture* in_texture, float in_scale);
	~Road();

	void setImpedence(int in_impedence);
};

