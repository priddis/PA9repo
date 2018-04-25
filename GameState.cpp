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
	uiList = new std::vector<UI*>;
	texMap = GameState::loadTextureFiles();

	//tile map stuff. future put in menu?
	tileMapPtr = new tileMap(texMap, 1);
	tileMapPtr->openMap("firstMap.txt");

	//testing tilemap
	//tileMapPtr->getTileInfo(19, 19)->getTerrainPtr();
	
	//Cursor initialization
	Cursor* mainCursor = new Cursor(tileSize, texMap->at("Cursor"));
	uiList->push_back(mainCursor);

	//currentPlayer is the player that is currently making their turn
	//true = team1, false = team2
	//4/24 modifying this slightly. extensible to more than two teams but also aligning to team "1" and "2" for consitancy. need to start at player 1
	currentPlayer = 1;

	//TODO: when tilemap is complete add code to get dimensions here
	//tilemap getMaxX and getMaxY give these values
  
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


Camera * GameState::getCamera()
{
	return cam;
}

void GameState::setPlayerCount(int in_playerCount) {
	playerCount = in_playerCount;
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

std::map<std::string, sf::Texture*>* GameState::getTexMap() {
	return texMap;
}