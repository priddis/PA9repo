#include "header/Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* pTexture = new sf::Texture();
	if (!(*pTexture).loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}
	

	setTexture(pTexture);
}

Cursor::Cursor(sf::Texture * inTex) : UI(inTex)
{

}

void Cursor::update(KeyState &curState) {
	if (counter % 5 == 0) {
		if (curState.w)
			uiSprite.move(0, -100);
		if (curState.a)
			uiSprite.move(-100, 0);
		if (curState.s)
			uiSprite.move(0, 100);
		if (curState.d)
			uiSprite.move(100, 0);
	}
	counter++;
}
