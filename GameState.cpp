/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"
#include "entities/Entity.h"
//for cout test
//#include <iostream>


GameState::GameState()
{
	//tw. now list obj not a pointer to a list obj. so need to construct here
	//spriteList = new std::list<sf::Sprite*>;
	
	keys.rmb = false;
	keys.lmb = false;
	keys.a = false;

	//this will be different when handling many textures.. data structure to hold it... but probably will exist here in a different form
	texture_tank = new sf::Texture;
	texture_tank->loadFromFile("assets/texture.png");
}

GameState::~GameState() {

	//removing the below line. any remaining list mem should dealloc itself if i take care of the heap'd mem like below
	//spriteList.clear();

	for (sf::Sprite* spr : spriteList) {
		delete spr;
	}

	//replaced below line with a loop to delete each alloc'd item
	//delete spriteList;
}

std::list<sf::Sprite*>& GameState::getSprites()
{
	return spriteList;
}

KeyState & GameState::getKeys()
{
	return keys;
}
