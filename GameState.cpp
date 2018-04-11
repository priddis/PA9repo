#include "GameState.h"

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


