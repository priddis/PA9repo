#pragma once
#include <SFML/Graphics.hpp>


class UI : public sf::Drawable
{
private:
	sf::Vector2<int> position;
	sf::Vector2<int> size;
	sf::Sprite uiSprite;
	sf::Texture uiTexture; // Needed for the texture to exist.

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	UI(void) {};
	UI(sf::Sprite Sprite);
	UI(sf::Sprite Sprite, sf::Color Color);
	UI(sf::Sprite Sprite, sf::Texture Texture);

	// Function to handle updates for each derived.
	virtual void update() {};

	// Get
	sf::Vector2<int> UI::getPosition() { return position; }
	sf::Vector2<int> UI::getSize() { return size; }

protected:
	// Set
	void UI::setTexture(sf::Texture Texture);
	void UI::setPosition(int x, int y) { position.x = x; position.y = y; }
	void UI::setSize(int width, int height) { size.x = width; size.y = height; }
};