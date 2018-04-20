#include "header/EventManager.h"

//EventManager is a list of functions to handle events such as input


//handle event is the function that is handed events and decides what actions to take

namespace EventManager {

	//the handleEvent function looks at the event and determines what functions to call based on that event
	void handleEvent(sf::Event & ev, KeyState &keys)
	{
		
		//key presses
		if (ev.type == sf::Event::KeyPressed) {
			if (ev.key.code == sf::Keyboard::A) {
				aKeyDown(keys);
			}
			if (ev.key.code == sf::Keyboard::D) {
				dKeyDown(keys);
			}
			if (ev.key.code == sf::Keyboard::S) {
				sKeyDown(keys);
			}
			if (ev.key.code == sf::Keyboard::W) {
				wKeyDown(keys);
			}
			if (ev.key.code == sf::Keyboard::Space) {
				spaceKeyDown(keys);
			}
			if (ev.key.code == sf::Keyboard::LShift) {
				lshiftKeyDown(keys);
			}

		}

		//key releases
		if (ev.type == sf::Event::KeyReleased) {
			if (ev.key.code == sf::Keyboard::A) {
				aKeyUp(keys);
			}
			if (ev.key.code == sf::Keyboard::D) {
				dKeyUp(keys);
			}
			if (ev.key.code == sf::Keyboard::S) {
				sKeyUp(keys);
			}
			if (ev.key.code == sf::Keyboard::W) {
				wKeyUp(keys);
			}
			if (ev.key.code == sf::Keyboard::Space) {
				spaceKeyUp(keys);
			}
			if (ev.key.code == sf::Keyboard::LShift) {
				lshiftKeyUp(keys);
			}
		}


		//mouse button presses
		if (ev.type == sf::Event::MouseButtonPressed){
			if (ev.mouseButton.button == sf::Mouse::Right){
				rightMouseButtonDown(keys);
			}
			if (ev.mouseButton.button == sf::Mouse::Left){
				leftMouseButtonDown(keys);
			}
		}


		//mouse button release
		if (ev.type == sf::Event::MouseButtonReleased){
			if (ev.mouseButton.button == sf::Mouse::Left){
				leftMouseButtonUp(keys);
			}
			if (ev.mouseButton.button == sf::Mouse::Right){
				rightMouseButtonUp(keys);
			}
		}
	}

	//setting the bools in KeyState
	void aKeyUp(KeyState &keys) {
		keys.a = false;
	}
	void aKeyDown(KeyState &keys) {
		keys.a = true;
	}
	void dKeyUp(KeyState &keys) {
		keys.d = false;
	}
	void dKeyDown(KeyState &keys) {
		std::cout << "pressed d";
		keys.d = true;
	}
	void wKeyUp(KeyState & keys){
		keys.w = false;
	}
	void wKeyDown(KeyState & keys) {
		keys.w = true;
	}
	void sKeyUp(KeyState & keys) {
		keys.s = false;
	}
	void sKeyDown(KeyState & keys) {
		keys.s = true;
	}

	void spaceKeyUp(KeyState & keys){
		keys.space = false;
	}

	void spaceKeyDown(KeyState & keys){
		keys.space = true;
	}

	void lshiftKeyUp(KeyState & keys){
		keys.lshift = false;
	}

	void lshiftKeyDown(KeyState & keys){
		keys.lshift = true;
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