#pragma once
#include <SFML/Graphics.hpp>
#include "header\KeyState.h"
#include "Camera.h"
#include <iostream>

class UI : public sf::Drawable
{
private:
	
	
public:
	UI(void) { counter = 0; };
	UI(sf::Texture *texture);
	UI(sf::Sprite Sprite);
	UI(sf::Sprite Sprite, sf::Color Color);
	UI(sf::Sprite Sprite, sf::Texture Texture);

	virtual void update(KeyState &curState, Camera* cam);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

	// Set
	void UI::setTexture(sf::Texture* &Texture);
	sf::Sprite uiSprite;
	sf::Texture* uiTexture; // Needed for the texture to exist.
	int counter;
};
