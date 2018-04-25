#pragma once
#include <SFML/Graphics.hpp>
#include "header\KeyState.h"
#include "Camera.h"
#include "tileInfo.h"
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
	~UI() {}

	virtual void update(KeyState &curState, Camera* cam);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* uiTexture; // Needed for the texture to exist.

	std::string identifier;

protected:


	int counter;
	// Set
	void UI::setTexture(sf::Texture* &Texture);
	sf::Sprite uiSprite;


};
