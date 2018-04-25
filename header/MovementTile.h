#pragma once
#include "UI.h"

class MovementTile : public UI {

private:
	int tSize;
	int posY;
	int posX;

public:


	MovementTile();
	MovementTile(int tileSize, sf::Texture* inTex, int x, int y, Camera* cam);

	~MovementTile() {}

	void update(KeyState &curState, Camera* cam);

	int getY();
	int getX();
};
