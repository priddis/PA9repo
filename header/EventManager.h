//EventManager is a list of functions to handle events such as input
//The functions are under a namespace so EventManager does not need to be instantiated

#include <SFML/Graphics.hpp>
#include "header/GameState.h"
#include <iostream>

namespace EventManager {

	void handleEvent(sf::Event &ev, KeyState &keys);
	
	void aKeyUp(KeyState &keys);
	void aKeyDown(KeyState & keys);
	void dKeyDown(KeyState &keys);
	void leftMouseButtonUp(KeyState &keys);
	void leftMouseButtonDown(KeyState &keys);
	void rightMouseButtonUp(KeyState &keys);
	void rightMouseButtonDown(KeyState &keys);

}