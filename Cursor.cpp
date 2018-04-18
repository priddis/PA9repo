#pragma once
#include "Cursor.h"

Cursor::Cursor(void) {
	sf::Texture Texture;
	if (!Texture.loadFromFile("cursor.png"))
		return;
	
	UI::setTexture(Texture);
}