#include "header/Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* pTexture = new sf::Texture();
	if (!(*pTexture).loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}
	

	setTexture(pTexture);
}

Cursor::Cursor(int tileSize,  sf::Texture * inTex) : UI(inTex)
{
	tSize = tileSize;
}

void Cursor::update(KeyState &curState) {
	if (counter % 8 == 0) {
		if (curState.w)
			uiSprite.move(0, -tSize);
		if (curState.a)
			uiSprite.move(-tSize, 0);
		if (curState.s) {
			uiSprite.move(0, tSize);
		}
		if (curState.d)
			uiSprite.move(tSize, 0);
	}
	counter++;
}
