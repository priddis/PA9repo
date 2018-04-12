#include "EventManager.h"
//handle event is the function that is handed events and decides what actions to take
void EventManager::handleEvent(sf::Event & ev)
{
	if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::A)) {
		aKey();
	}
	if (ev.type == sf::Event::MouseButtonPressed)
	{
		if (ev.mouseButton.button == sf::Mouse::Right)
		{
			rmb();
		}
		if ( ev.mouseButton.button == sf::Mouse::Left ) {
			lmb();
		}
	}

}
void lmb() {

}
void rmb() {

}
void aKey() {

}
