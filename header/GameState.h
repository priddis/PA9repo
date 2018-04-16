/*A GameState object is an object that should contain 
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct 
*/
 
#pragma once
#include <list>
#include <SFML/Graphics.hpp>


struct KeyState {
	bool lmb;
	bool rmb;
	bool a;

};

class GameState{

private:

	//list of sprites to display to the screen
	std::list<sf::Sprite>* spriteList;

	//list of keys currently held down
	KeyState keys;


public:
	GameState();
	~GameState();

	std::list<sf::Sprite>* & getSprites();

	KeyState & getKeys();
};