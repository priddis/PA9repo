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
	if (counter%5==0) {
		if (curState.w)
			uiSprite.move(0, -100);
		if (curState.a)
			uiSprite.move(-100, 0);
		if (curState.s)
			uiSprite.move(0, 100);
		if (curState.d)
			uiSprite.move(100, 0);
	}
	counter++;
}