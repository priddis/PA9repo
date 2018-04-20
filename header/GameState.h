/*A GameState object is an object that should contain 
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct 
*/
 
#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "KeyState.h"

class GameState{

private:

	//list of sprites to display to the screen
	std::vector<sf::Sprite>* spriteList;
	std::vector<UI>* uiList;
	
	//list of keys currently held down
	KeyState keys;


public:
	GameState();
	~GameState();

	std::vector<sf::Sprite>* & getSprites();
	std::vector<UI>* & getUIElements();

	void addUI(UI &newUI);

	KeyState & getKeys();
};