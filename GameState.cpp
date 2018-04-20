/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"

GameState::GameState()
{
	Cursor cursor;
	spriteList = new std::vector<sf::Sprite>;
	uiList = new std::vector<UI>;
	uiList->push_back(cursor);

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

std::vector<UI>* & GameState::getUIElements() {
	return uiList;
}

std::vector<sf::Sprite>*& GameState::getSprites()
{
	return spriteList;
}

KeyState & GameState::getKeys()
{
	return keys;
}

void GameState::addUI(UI &newUI) {
	uiList->push_back(newUI);
}

