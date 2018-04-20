#pragma once
#include <SFML/Graphics.hpp>
#include "header\KeyState.h"
#include <iostream>

class UI : public sf::Drawable
{
private:
	sf::Vector2<int> position;
	sf::Vector2<int> size;
	sf::Sprite uiSprite;
	sf::Texture* uiTexture; // Needed for the texture to exist.

public:
	UI(void) {};
	UI(sf::Sprite Sprite);
	UI(sf::Sprite Sprite, sf::Color Color);
	UI(sf::Sprite Sprite, sf::Texture Texture);

	void update(KeyState &curState);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Get
	sf::Vector2<int> UI::getPosition() { return position; }
	sf::Vector2<int> UI::getSize() { return size; }

protected:

	// Set
	void UI::setTexture(sf::Texture* &Texture);
	void UI::setPosition(int x, int y) { position.x = x; position.y = y; }
	void UI::setSize(int width, int height) { size.x = width; size.y = height; }
};