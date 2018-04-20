#include "header/Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* pTexture = new sf::Texture();
	if (!(*pTexture).loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}
	
	setTexture(pTexture);
}