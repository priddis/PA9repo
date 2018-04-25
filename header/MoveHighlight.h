#pragma once
#include "UI.h"

//MoveHighlight is a indicator that is overlayed tiles that the selected unit can move to.
//the txture is a blue square with 50% opacity
class MoveHighlight : public UI {

private:
	int tSize;
	int posY;
	int posX;

public:

	MoveHighlight();
	MoveHighlight(int tileSize, sf::Texture* inTex,int  x,int y, Camera* cam);

	void update(KeyState &curState, Camera* cam);

	int getY();
	int getX();

};
