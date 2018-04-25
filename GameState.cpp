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
	//4/24 modifying this slightly. extensible to more than two teams but also aligning to team "1" and "2" for consitancy. need to start at player 1
	currentPlayer = 1;

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
	selectedUnit = nullptr;

	selectedX = 0;
	selectedY = 0;

	//when a unit is selected, the possible move coordinates will be put in this list
	moveList = new std::set<std::pair<int, int>>();
	//but if there is an enemy blocking their move, it is put in this list
	enemyList = new std::set<std::pair<int, int>>();



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

void GameState::attack(Unit*& attacker, Unit*& target) {
	//sound!
	//explosion!
	//animation!

	//first, get how the targeted unit will modify the incoming damage
	int damage = target->getDefensiveModifier(attacker->getUnitType());
	//then get the attacking units attack damage and sum
	damage = damage + attacker->getAttackDamage();
	//reduce the targets health (down to 0 max)
	target->setCurrentHealth(target->getCurrentHealth() - damage);
	//if we hit 0, target dies
	if (target->getCurrentHealth() == 0) die(target);

}

void GameState::die(Unit*& in_unit) {
	delete in_unit;
	in_unit = nullptr;
}


void GameState::drawMoveUI(Unit* pUnit, int unitPosX, int unitPosY) {

	for (int i = 0; i < tileMapPtr->getMaxX(); i++) {
		for (int j = 0; j < tileMapPtr->getMaxY(); j++) {
			
			//tileMapPtr->getTileInfo(i,j)->getTerrainPtr()->getTraversable()
			if (  tileMapPtr->getTileInfo(i, j)->getUnitPtr() == nullptr && pUnit->getCurrentTravelRange() >= std::abs(i - unitPosX) + std::abs(j - unitPosY) ) {
				uiList->push_back(new MovementTile(tileSize, texMap->at("Move"), i, j, cam));
				moveList->insert(std::pair<int, int>(i, j));
			}
			//but if theres a unit in our move area, lets record it
			else if (tileMapPtr->getTileInfo(i, j)->getUnitPtr() != nullptr && //if the selected tile has a unit
					pUnit->getCurrentTravelRange() >= std::abs(i - unitPosX) + std::abs(j - unitPosY && //and its in range of our move
					selectedUnit->getTeam() != tileMapPtr->getTileInfo(i, j)->getUnitPtr()->getTeam())) //and its not the same team
			{
				enemyList->insert(std::pair<int, int>(i, j));
			}
		}
	}
}

void GameState::setPlayerCount(int in_playerCount) {
	playerCount = in_playerCount;
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


		if (moveList->count(std::pair<int, int>(x, y))) {
			currentTile->setUnitPtr(selectedUnit);
			tileMapPtr->getTileInfo(selectedX, selectedY)->setUnitPtr(nullptr);
		}
		removeUI("MovementTile");
		//std::cout << "testing move tile destruction" << std::endl;
		moveList->clear();
		
		////tw workspace
		if (enemyList->count(std::pair<int, int>(x, y))) {
			std::cout << "targets initial health: " << tileMapPtr->getTileInfo(x, y)->getUnitPtr()->getCurrentHealth() << std::endl;
			attack(selectedUnit, tileMapPtr->getTileInfo(x, y)->getUnitPtr());
			if (tileMapPtr->getTileInfo(x, y)->getUnitPtr() == nullptr) {
				std::cout << "target is dead! " << std::endl;
			}
			else std::cout << "targets health after the attack: " << tileMapPtr->getTileInfo(x, y)->getUnitPtr()->getCurrentHealth() << std::endl;

			//currentTile->setUnitPtr(selectedUnit);
			//tileMapPtr->getTileInfo(selectedX, selectedY)->setUnitPtr(nullptr);
		} 
		removeUI("MovementTile");
		//std::cout << "testing move tile destruction" << std::endl;
		moveList->clear();
		///////////////////
	}
	else if(currentTile->getUnitPtr() != NULL && movementMode == false) { // Is there a unit under cursor?
		movementMode = true;
		drawMoveUI(currentTile->getUnitPtr(), x, y);
		selectedUnit = currentTile->getUnitPtr();
		selectedX = x;
		selectedY = y;
		
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
	Unit* tempUnit = nullptr;
	int x, y = 0;
	//travel down the entire x 
	for (x = 0; x < tileMapPtr->getMaxX(); x++) {
		//travel down the entire y
		for (y = 0; y < tileMapPtr->getMaxY(); y++) {
			//get the unit in this x, y coordinate
			tempUnit = tileMapPtr->getTileInfo(x, y)->getUnitPtr();
			//if the tile contains a unit owned by the current player, reset its travel range to max
			if (tempUnit->getTeam() == currentPlayer) {
				tempUnit->setCurrentTravelRange(tempUnit->getMaxTravelRange());
			}
		}
	}
	if (currentPlayer < playerCount) {
		currentPlayer++;
	}
	else {
		currentPlayer = 1;
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
	textureMap->at("Tank")->loadFromFile("assets/pig.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Road", new sf::Texture()));
	textureMap->at("Road")->loadFromFile("assets/Road.png");

	textureMap->insert(std::pair<std::string, sf::Texture*>("Soldier", new sf::Texture()));
	textureMap->at("Soldier")->loadFromFile("assets/cow.png");

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

	if (keys.space && !keyPressed ) {
		keyPressed = true;
		action();

	}
	else if(getKeys().space == false) {
		keyPressed = false;
	}



	counter++;
}

std::map<std::string, sf::Texture*>* GameState::getTexMap() {
	return texMap;
}