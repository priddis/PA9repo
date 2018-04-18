/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"

GameState::GameState()
{
	spriteList = new std::list<sf::Sprite>;

	//currentPlayer is the player that is currently making their turn
	//true = team1, false = team2
	currentPlayer = true;

	keys.rmb = false;
	keys.lmb = false;

	keys.a = false;
	keys.d = false;
	keys.w = false;
	keys.s = false;

	keys.space = false;
	keys.lshift = false;
}

GameState::~GameState() {

	spriteList->clear();


	delete spriteList;
}

std::list<sf::Sprite>*& GameState::getSprites(){
	return spriteList;
}

KeyState & GameState::getKeys()
{
	return keys;
}

void GameState::endTurn() {
	currentPlayer = !currentPlayer;
}

