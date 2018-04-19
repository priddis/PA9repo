//not much needed for this class. this is an abstract class. derived classes will be used for specific terrain tiles.
//tw 4/18/18

#pragma once
#include <SFML/Graphics.hpp>

class Terrain :
	public sf::Sprite
{
	//not much needed for this class
protected:
	int impedence;
public:
	Terrain(sf::Texture* in_texture, float in_scale);
	~Terrain();

	virtual void setImpedence(int in_impedence) = 0;
};