#include "header/Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* TexturePtr = new sf::Texture();
	if (!(*TexturePtr).loadFromFile("assets/cursor.png")) {
		std::cout << "Could not load cursor.png" << std::endl;
	}
	
	setTexture(TexturePtr);

}