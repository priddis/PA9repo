/*A GameState object is an object that should contain
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct
*/


#include "header/GameState.h"

GameState::GameState()
{
}

GameState::GameState(int newTileSize, int ResX, int ResY)
{
	tileSize = newTileSize;

	// lists for sprites and UI to be displayed
	spriteList = new std::list<sf::Sprite>;
	uiList = new std::list<UI*>;
	texMap = GameState::loadTextureFiles();

	//tile map stuff. future put in menu?
	tileMapPtr = new tileMap(texMap, 1);
	tileMapPtr->openMap("firstMap.txt");

	//testing tilemap
	//tileMapPtr->getTileInfo(19, 19)->getTerrainPtr();
	
	//Cursor initialization
	mainCursor = new Cursor(tileSize, texMap->at("Cursor"));
	uiList->push_back(mainCursor);

	//currentPlayer is the player that is currently making their turn
	//true = team1, false = team2
	currentPlayer = true;
	turnCounter = 1;

	//single presses
	keyPressed = false;
	counter = 0;
  
	cam = new Camera( ResX / tileSize, ResY / tileSize, tileMapPtr->getMaxX() , tileMapPtr->getMaxY());

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

	movementMode = false;
}

GameState::~GameState() {

	spriteList->clear();

	delete spriteList;
	delete tileMapPtr;
}

std::list<sf::Sprite>*& GameState::getSprites(){
	return spriteList;
}

std::list<UI*>*& GameState::getUIElements() {
	return uiList;
}

KeyState & GameState::getKeys()
{
	return keys;
}

//Unit1 is attacking unit2
//return type?
void GameState::attack(Unit* attacker, Unit* target) {
	//sound!
	//explosion!
	//animation!
//	target->reduceHealthAttacked(attacker->getAttackDamage(), )

	/*
	unit2->setCurrentHealth( unit2->getCurrentHealth() - unit1->getAttackDamage() );

	if(unit2->getCurrentHealth() <= 0){
	delete unit2;
	}
	*/
}


//TODO:
//Death
//not sure how to work in death yet
//Current thoughts are that if current hp is set below zero, we delete the pointer but this could mess up later things
//tw: i think this is good. dealloc unit, set tileInfo's unit ptr to nullptr

//	unit2->setCurrentHealth( unit2->getCurrentHealth() - unit1->getAttackDamage() );

	/*if(unit2->getCurrentHealth() <= 0){
		delete unit2;
	}
	*/

//}

void GameState::moveUnit(Unit* pUnit) {
	int unitPosX = pUnit->getPosition().x / 100;
	int unitPosY = pUnit->getPosition().y / 100;

	for (int i = 0; i < tileMapPtr->getMaxX()-1; i++) {
		for (int j = 0; j < tileMapPtr->getMaxY()-1; j++) {
			int range = std::abs(i - unitPosX) + std::abs(j - unitPosY);
			
			if (range <= pUnit->getTravelRange()) {
				uiList->push_back(new MovementTile(tileSize, texMap->at("Move"), i, j, cam));
			}
		}
	}
}

void GameState::removeUI(std::string id) { // Removes UI with a specified identifier
	for (UI* element : *getUIElements()) {
		if (element->identifier == id) {
			getUIElements()->remove(element);
			delete element;
		}
	}
}

void GameState::action() {
	int x = mainCursor->getX();
	int y = mainCursor->getY();

	tileInfo* currentTile = tileMapPtr->getTileInfo(x, y);

	if (movementMode == true) {
		movementMode = false;
		removeUI("MovementTile");
		std::cout << "wat" << std::endl;
	}
	else if(currentTile->getUnitPtr() != NULL && movementMode == false) { // Is there a unit under cursor?
		movementMode = true;
		moveUnit(currentTile->getUnitPtr());
	}
}

Cursor * GameState::getCursor()
{
	return mainCursor;
}

Camera * GameState::getCamera()
{
	return cam;
}

//ends the turn by switching players and adds to the turn counter whenever player1's turn begins
void GameState::endTurn() {
	currentPlayer = !currentPlayer;

	if (currentPlayer) {
		turnCounter++;
	}
}

void GameState::setTileSize(int newSize)
{

	tileSize = newSize;
	std::cout << "\n new tilesize: " << newSize;
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

	textureMap->insert(std::pair<std::string, sf::Texture*>("Soldier", new sf::Texture()));
	textureMap->at("Soldier")->loadFromFile("assets/Soldier.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Grass", new sf::Texture()));
	textureMap->at("Grass")->loadFromFile("assets/Grass.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Move", new sf::Texture()));
	textureMap->at("Move")->loadFromFile("assets/Move.png");

	return textureMap;
}

tileMap*& GameState::getTileMap() {
	return tileMapPtr;
}

void GameState::update() {

	if (getKeys().space && !keyPressed) {
		action();
		keyPressed = true;
	}

	if (counter % 15 == 0)
		keyPressed = false;

	counter++;
}

std::map<std::string, sf::Texture*>* GameState::getTexMap() {
	return texMap;
}