#pragma once
#include "UI.h"

//The cursor class is a UI object controlled by the player. The cursor is how the player interacts with the rest of the game.

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