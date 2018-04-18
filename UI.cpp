#include "UI.h"

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(uiSprite, states);
}