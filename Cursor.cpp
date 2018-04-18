#include "Cursor.h"

Cursor::Cursor(void) {
	sf::Texture* TexturePtr = new sf::Texture();
	(*TexturePtr).loadFromFile("cursor.png");
	
	UI::setTexture(TexturePtr);

}

void Cursor::moveLeft() {
	UI::setPosition(UI::getPosition().x - 100, UI::getPosition().y);
}

void Cursor::moveRight() {
	UI::setPosition(UI::getPosition().x + 100, UI::getPosition().y);
}

void Cursor::moveUp() {
	UI::setPosition(UI::getPosition().x, UI::getPosition().y + 100);
}

void Cursor::moveDown() {
	UI::setPosition(UI::getPosition().x, UI::getPosition().y - 100);
}

void Cursor::update() { 
}