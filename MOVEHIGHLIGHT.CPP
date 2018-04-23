#include "header\MoveHighlight.h"

MoveHighlight::MoveHighlight()
{

}

MoveHighlight::MoveHighlight(int tileSize, sf::Texture * inTex, int  x, int y, Camera * cam) : UI(inTex)
{
	tSize = tileSize;
	std::cout << tSize << "\n";
	posX = x;
	posY = y;
	//uiSprite.move(x * tSize, y * tSize);
	uiSprite.move( (x - cam->getCamX()) * tSize, (y - cam->getCamY() ) * tileSize);
	//std::cout << cam->getCamX();

}

void MoveHighlight::update(KeyState & curState, Camera * cam)
{
	//std::cout << "x:" << ((posX + cam->getCamX()) * tSize) << " y:" << (posY + cam->getCamY()) * tSize << std::endl;
	uiSprite.setPosition((posX - cam->getCamX()) * tSize, (posY - cam->getCamY()) * tSize);
}

int MoveHighlight::getY()
{
	return posY;
}

int MoveHighlight::getX()
{
	return posX;
}

