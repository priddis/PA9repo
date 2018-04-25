
#pragma once
#include "Terrain.h"

class Grass :
	public Terrain
{
public:
	Grass(sf::Texture* in_texture, float in_scale);
	~Grass();

	void setImpedence(int in_impedence);
};

