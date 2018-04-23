#include "header/Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* pTexture = new sf::Texture();
	if (!(*pTexture).loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}


	setTexture(pTexture);
}

Cursor::Cursor(int tileSize, sf::Texture * inTex) : UI(inTex)
{
	tSize = tileSize;
	posX = 0;
	posY = 0;
}

//most of this complicated logic is to make the camera scroll when trying to move beyond what is currently being draw
//to screen
void Cursor::update(KeyState &curState, Camera* cam) {

	if (counter % 8 == 0) {
		//std::cout << "cursor: " << posX << " " << posY << "\n";
		//std::cout << "max:" << cam->getMaxY();
		if (curState.w) {

			if (posY == cam->getCamY()) {
				cam->moveCamera(0, -1);
			}
			else {
				uiSprite.move(0, -tSize);
			}
			
			if (posY > 0) {
				posY--;
			}
		}
		if (curState.a) {

			if (posX == cam->getCamX()) {
				cam->moveCamera(-1, 0);
			}
			else {
				uiSprite.move(-tSize, 0);
			}
			if (posX > 0) {
				posX--;
			}

		}
		if (curState.s) {
			if (posY == cam->getCamY() + cam->getCamHeight() - 1) {
				cam->moveCamera(0, 1);
			}
			else {
				uiSprite.move(0, tSize);
			}
			posY++;


			if (posY > cam->getMaxY() - 1) {
				posY = cam->getMaxY() - 1;
			}

		}
		if (curState.d) {
			if (posX == cam->getCamX() + cam->getCamWidth() - 1) {
				cam->moveCamera(1, 0);
			}
			else {
				uiSprite.move(tSize, 0);
			}
			posX++;
			if (posX > cam->getMaxX() - 1) {
				posX = cam->getMaxX() - 1;
			}
		}

	}
	counter++;
}

void Cursor::movePos(int xOffset, int yOffset)
{
	posY += yOffset;
	posX += xOffset;
}
