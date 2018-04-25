#include "header\MoveHighlight.h"

MoveHighlight::MoveHighlight()
{

}

MoveHighlight::MoveHighlight(int tileSize, sf::Texture * inTex, int  x, int y, Camera * cam) : UI(inTex)
{
	tSize = tileSize;
	//std::cout << tSize << "\n";

	//x,y are positions in the grid that tie a the object to a specific position

	posX = x;
	posY = y;

	//this sets the position the fram the object is instantiated
	uiSprite.move( (x - cam->getCamX()) * tSize, (y - cam->getCamY() ) * tileSize);
	//std::cout << cam->getCamX();

}

//MoveHighlight objects should not move with the camera
//this function will make it appear that the object is stationary
void MoveHighlight::update(KeyState & curState, Camera * cam)
{
	//std::cout << "x:" << ((posX + cam->getCamX()) * tSize) << " y:" << (posY + cam->getCamY()) * tSize << std::endl;

	//this line moves the object so it appears  to keep its position in the grid
	uiSprite.setPosition((posX - cam->getCamX()) * tSize, (posY - cam->getCamY()) * tSize);
}

//getters for position

int MoveHighlight::getY()
{
	return posY;
}

int MoveHighlight::getX()
{
	return posX;
}

