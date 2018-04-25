#include "header/Cursor.h"
#include <iostream>

//this constructor should not be used anymore
//left for testing purposes
Cursor::Cursor(void) {
	sf::Texture* pTexture = new sf::Texture();
	if (!(pTexture)->loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}
	setTexture(pTexture);

	posX = 0;
	posY = 0;
	identifier = "Cursor";
}

Cursor::Cursor(int tileSize, sf::Texture * inTex) : UI(inTex)
{
	tSize = tileSize;
	posX = 0;
	posY = 0;
	identifier = "Cursor";
}

//most of this complicated logic is to make the camera scroll 
//when trying to move beyond what is currently being drawn to screen
//the boundaries of the map are also accounted for
void Cursor::update(KeyState &curState, Camera* cam) {

	//the counter prevents the cursor from moving every frame
	//we want it to be easy to stop the cursor on a certian box on the grid
	if (counter % 8 == 0) {
		//std::cout << "cursor: " << posX << " " << posY << "\n";
		//std::cout << "max:" << cam->getMaxY();
		if (curState.w) {

			//if the cursor is at the edge of the screen and tries to move past it
			//then the camera needs to move instead of the cursor
			if (posY == cam->getCamY()) {
				cam->moveCamera(0, -1);
			}
			else {
				uiSprite.move(0, -tSize);
			}
			//this prevents the cursor from going off the screen on the topside
			if (posY > 0) {
				posY--;
			}
		}
		//these other if statments work off the same logic as the above one, just for different directions
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

int Cursor::getX() {
	return posX;
}

int Cursor::getY() {
	return posY;
}

void Cursor::movePos(int xOffset, int yOffset)
{
	posY += yOffset;
	posX += xOffset;
}


