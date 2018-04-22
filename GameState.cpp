/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"

GameState::GameState()
{

	// lists for sprites and UI to be displayed
	spriteList = new std::list<sf::Sprite>;
	uiList = new std::vector<UI*>;
	texMap = GameState::loadTextureFiles();

	//tile map stuff. future put in menu?
	tileMapPtr = new tileMap(texMap, 1);
	tileMapPtr->openMap("firstMap.txt");
	
	Cursor* mainCursor = new Cursor(texMap->at("Cursor"));
	uiList->push_back(mainCursor);

	//currentPlayer is the player that is currently making their turn
	//true = team1, false = team2
	currentPlayer = true;
	turnCounter = 1;


	//TODO: when tilemap is complete add code to get dimensions here
	//int mapSizeX = 
	//int mapSizeY = 



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
	delete tileMapPtr;
}

std::list<sf::Sprite>*& GameState::getSprites(){
	return spriteList;
}

std::vector<UI*>*& GameState::getUIElements() {
	return uiList;
}

KeyState & GameState::getKeys()
{
	return keys;
}

//Unit1 is attacking unit2

//TODO:
//Death
//not sure how to work in death yet
//Current thoughts are that if current hp is set below zero, we delete the pointer but this could mess up later things
void GameState::attack(Unit* unit1, Unit* unit2){


	unit2->setCurrentHealth( unit2->getCurrentHealth() - unit1->getAttackDamage() );

	/*if(unit2->getCurrentHealth() <= 0){
		delete unit2;
	}
	*/

}

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


//runs at launch, loads the all the texture files needed for sprites
std::map<std::string, sf::Texture*>* GameState::loadTextureFiles()
{

	std::map<std::string, sf::Texture*>* textureMap = new std::map<std::string, sf::Texture*>();

	textureMap->insert(std::pair<std::string, sf::Texture*>("Cursor", new sf::Texture()));
	textureMap->at("Cursor")->loadFromFile("assets/cursor.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Tank", new sf::Texture()));
	textureMap->at("Tank")->loadFromFile("assets/Tank.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Road", new sf::Texture()));
	textureMap->at("Road")->loadFromFile("assets/Road.png");


	return textureMap;
}

tileMap*& GameState::getTileMap() {
	return tileMapPtr;
}
