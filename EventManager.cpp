#include "header/EventManager.h"

//EventManager is a list of functions to handle events such as input
//handle event is the function that is handed events and decides what actions to take

namespace EventManager {

	//the handleEvent function looks at the event and determines what functions to call based on that event
	void handleEvent(sf::Event & ev, KeyState &keys)
	{

		//key presses
		if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::A)) {
			aKeyDown(keys);
		}
		if ((ev.type == sf::Event::KeyReleased) && (ev.key.code == sf::Keyboard::A)) {
			aKeyUp(keys);
		}
		if ((ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::D)) {
			dKeyDown(keys);
		}


		//mouse button presses

		if (ev.type == sf::Event::MouseButtonPressed)
		{
			if (ev.mouseButton.button == sf::Mouse::Right)
			{
				rightMouseButtonDown(keys);
			}
			if (ev.mouseButton.button == sf::Mouse::Left)
			{
				leftMouseButtonDown(keys);
			}
		}


		//mouse button release

		if (ev.type == sf::Event::MouseButtonReleased)
		{
			if (ev.mouseButton.button == sf::Mouse::Left)
			{
				leftMouseButtonUp(keys);
			}

			if (ev.mouseButton.button == sf::Mouse::Right)
			{
				rightMouseButtonUp(keys);
			}
		}
	}

	void aKeyUp(KeyState &keys) {
		std::cout << "Testing the 'A' key press\n";
		keys.a = true;
	}
	void aKeyDown(KeyState &keys) {
		std::cout << "Testing the 'A' key release\n";
		keys.a = false;
	}
	void dKeyDown(KeyState &keys) {
		std::cout << "Testing the 'D' key press\n";
		keys.a = true;
	}

	void leftMouseButtonDown(KeyState &keys) {
		std::cout << "Testing leftMouseButton down\n";
		keys.lmb = true;
	}
	void leftMouseButtonUp(KeyState &keys) {
		std::cout << "Testing left leftMouseButton up \n";
		keys.lmb = false;
	}

	void rightMouseButtonDown(KeyState &keys) {
		std::cout << "Testing rightMouseButton down\n";
		keys.rmb = true;
	}

	void rightMouseButtonUp(KeyState &keys) {
		std::cout << "Testing rightMouseButton up\n";
		keys.rmb = false;
	}
}