#include "header/UI.h"

UI::UI(sf::Texture* texture) {
	counter = 0;
	uiTexture = texture;
	uiSprite.setTexture(*texture);


}

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

void UI::setTexture(sf::Texture* &texture) {
	uiSprite.setTexture(*texture);
}

void UI::update(KeyState &curState) {

}
