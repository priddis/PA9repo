/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"
#include "entities/Entity.h"
//for cout test
#include <iostream>


GameState::GameState()
{
	//tw. now list obj not a pointer to a list obj. so need to construct here
	//spriteList = new std::list<sf::Sprite*>;
	
	keys.rmb = false;
	keys.lmb = false;
	keys.a = false;

	//tw. loading the file for my test sprite/unit
	std:: cout << "texture success: " << texture_tank.loadFromFile("texture.png" ) << std::endl;
	//this is for testing only.... i only want to create one new tank... not used to the (basically) infinite loop structure... needed to find a place that would only run once
	test_newTank();
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

//what would be the most appropriate class for a function that instantiates an object and puts it on the screen? gamestate? or elsewhere?
//also this is just a sprite, and should be a derived unit class. that is the plan, just testing with sprite first and then moving to inherited unit class
void GameState::test_newTank()
{
	// Create a new sprite on the heap
	sf::Sprite* pMem = new sf::Sprite();
	//set its default texture
	pMem->setTexture(texture_tank);

	//set defaults position. in the future maybe this takes a tile coordinate parameter to set pos. 
	pMem->setPosition(10, 10);

	//setcolor temporarily while my loadtexture continues to fail....
	//this used to work. no longer, meh.
	pMem->setColor(sf::Color(000, 200, 000, 200));

	//add it to our Sprite list
	spriteList.push_front(pMem);

	//continuous drawing occurs in engine::drawsprites
}