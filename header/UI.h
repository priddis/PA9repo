#pragma once
#include <SFML/Graphics.hpp>
#include "header\KeyState.h"
#include <iostream>

class UI : public sf::Drawable
{
private:
	sf::Sprite uiSprite;
	sf::Texture* uiTexture; // Needed for the texture to exist.
	int counter;
	
public:
	UI(void) { counter = 0; };
	UI(sf::Texture *texture);
	UI(sf::Sprite Sprite);
	UI(sf::Sprite Sprite, sf::Color Color);
	UI(sf::Sprite Sprite, sf::Texture Texture);

	void update(KeyState &curState);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

	// Set
	void UI::setTexture(sf::Texture* &Texture);
};