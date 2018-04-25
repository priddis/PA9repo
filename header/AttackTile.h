#pragma once
#include "UI.h"

class AttackTile : public UI {

private:
	int tSize;
	int posY;
	int posX;

public:


	AttackTile();
	AttackTile(int tileSize, sf::Texture* inTex, int x, int y, Camera* cam);

	~AttackTile() {}

	void update(KeyState &curState, Camera* cam);

	int getY();
	int getX();
};
