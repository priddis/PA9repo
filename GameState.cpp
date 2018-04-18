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
	turnCounter = 1;


	//TODO: when tilemap is complete add code to get dimensions here
	//mapSizeX = 
	//mapSizeY = 



	//key assignments, by default all keys are set to false
	//false = key up, true = key down
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

/*void GameState::attack(Unit & unit1, Unit & unit2){
	unit2.getHP() -= unit1.getATK()

}*

/*void GameState::moveUnit(Unit & unit){

	

}
*/

//ends the turn by switching players and adds to the turn counter whenever player1's turn begins
void GameState::endTurn() {
	currentPlayer = !currentPlayer;

	if (currentPlayer) {
		turnCounter++;
	}
}

