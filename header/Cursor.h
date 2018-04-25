#pragma once
#include "UI.h"
//#include "Camera.h"
//#include "tileInfo.h"

class Cursor : public UI {
private:

	int tSize;

	//this is relative to the grid
	//these are not positions by pixels
	int posY;
	int posX;


public:
	Cursor();
	Cursor(int tileSize, sf::Texture* inTex);

	void update(KeyState &curState, Camera* cam);
	void movePos(int xOffset, int yOffset);

	int getX();
	int getY();

};