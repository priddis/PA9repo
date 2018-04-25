/*A GameState object is an object that should contain 
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, 
and a struct for the keys being pressed
*/
 
#pragma once
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "header/Unit.h"
#include "header/Cursor.h"
#include "MovementTile.h"
#include "KeyState.h"
#include "tileMap.h"
#include "Camera.h"

class GameState{

private:

	//list of sprites to display to the screen
	std::list<sf::Sprite>* spriteList;
	std::list<UI*>* uiList;

	Cursor *mainCursor;

	//modifying this a little bit
	//bool currentPlayer;
	//int turnCounter;

	int playerCount;
	int currentPlayer;

	int mapSizeX;
	int mapSizeY;
	
	int tileSize;

	//struct of keys currently held down
	KeyState keys;

	std::map<std::string, sf::Texture*>* texMap;
	tileMap* tileMapPtr;

	//runs at launch, loads the all the texture files needed for sprites
	//placed in gamestate for convenience
	std::map<std::string, sf::Texture*>* loadTextureFiles();

	Camera* cam;

	void moveUnit(Unit *pUnit);
	bool movementMode;

	bool keyPressed;
	int counter;
public:
	GameState();
	GameState(int newTileSize, int ResX, int ResY);
	~GameState();

	void update();
	//for access in engine currently
	tileMap*& getTileMap(); //should be const

	std::list<sf::Sprite>* & getSprites();
	std::list<UI*>* & getUIElements();
	void removeUI(std::string id);

	KeyState & getKeys();

	void attack(Unit*& attacker, Unit*& target);
	void die(Unit*& in_unit);

	void endTurn();
	void setPlayerCount(int in_playerCount = 2);

	void setTileSize(int newSize);

	void GameState::attack(Unit* unit1, Unit* unit2);
	void GameState::action();

	Cursor* getCursor();
	Camera* getCamera();

	std::map<std::string, sf::Texture*>* getTexMap();
};