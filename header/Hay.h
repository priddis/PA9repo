#pragma once

//A hay object is a simple terrain type that cannot be moved over

#include "Terrain.h"

class Hay : public Terrain {
public:
	Hay(sf::Texture* in_texture, float in_scale);
	~Hay();
};

