
#pragma once
#include "Terrain.h"

class Road : public Terrain {

public:
	Road(sf::Texture* in_texture, float in_scale);
	~Road();

	void setImpedence(int in_impedence);
};

