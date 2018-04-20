#include "header/UI.h"

UI::UI(sf::Sprite Sprite, sf::Color Color) {
	uiSprite = Sprite;
	uiSprite.setColor(Color);
}

UI::UI(sf::Sprite Sprite, sf::Texture Texture) {
	uiSprite = Sprite;
	uiSprite.setTexture(Texture);
}

UI::UI(sf::Sprite Sprite) {
	uiSprite = Sprite;
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(uiSprite, states);
}

void UI::setTexture(sf::Texture* &Texture) {
	uiTexture = Texture;
	uiSprite.setTexture(*uiTexture);
}

void UI::update(KeyState &curState) {
	if (curState.w)
		uiSprite.move(0, -1);
	if (curState.a)
		uiSprite.move(-1, 0);
	if (curState.s)
		uiSprite.move(0, 1);
	if (curState.d)
		uiSprite.move(1, 0);
}