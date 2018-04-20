#include "Cursor.h"
#include <iostream>

Cursor::Cursor(void) {
	sf::Texture* TexturePtr = new sf::Texture();
	(*TexturePtr).loadFromFile("cursor.png");
	
	setTexture(TexturePtr);

}