/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"


GameState::GameState()
{
	spriteList = new std::list<sf::Sprite>;
	
	keys.rmb = false;
	keys.lmb = false;
	keys.a = false;
}

GameState::~GameState() {

	spriteList->clear();


	delete spriteList;
}

std::list<sf::Sprite>*& GameState::getSprites()
{
	return spriteList;
}

KeyState & GameState::getKeys()
{
	return keys;
}


