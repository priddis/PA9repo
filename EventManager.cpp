#include "header/EventManager.h"
#include "header/GameState.h"
//handle event is the function that is handed events and decides what actions to take

namespace EventManager {

	//the handleEvent function 
	void handleEvent(sf::Event & ev, keyState keys)
	{


		if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::A)) {
			aKey();
		}

		if (ev.type == sf::Event::MouseButtonReleased) 
		{
			if (ev.mouseButton.button == sf::Mouse::Left) 
			{
				leftMouseButtonUp();
			}

			if (ev.mouseButton.button == sf::Mouse::Right) 
			{
				rightMouseButtonUp();
			}
		}


		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.mouseButton.button == sf::Mouse::Right)
			{
				rightMouseButtonDown();
			}
			if (ev.mouseButton.button == sf::Mouse::Left) 
			{
				leftMouseButtonDown();
			}
		}

	}


	void leftMouseButtonDown() {
		std::cout << "Testing leftMouseButton down\n";
	}
	void leftMouseButtonUp() {
		std::cout << "Testing left leftMouseButton up \n";
	}

	void rightMouseButtonDown() { 
		std::cout << "Testing rightMouseButton down\n";
	}

	void rightMouseButtonUp() {
		std::cout << "Testing rightMouseButton up\n";
	}

	void aKey() {
		std::cout << "Testing the \'A\' key\n";
	}


}



