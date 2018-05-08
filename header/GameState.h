/*A GameState object is an object that should contain 
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, 
and a struct for the keys being pressed
*/
 
#pragma once
#include <list>
#include <vector>
#include <set>
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

	//pointer to the cursor controlled by the player(s)
	Cursor *mainCursor;

	//number of players in current game
	int playerCount;

	//number of player currently moving
	int currentPlayer;

	//number of tiles in a row on the map
	int mapSizeX;

	//number of rows in a column
	int mapSizeY;
	
	//size of the side of a square tile ( in pixels)
	int tileSize;

	//struct of keys currently held down
	KeyState keys;

	//texMap is a map linking the name of a unit to a pointer of its texture. This is to ensure that only one texture is loaded per unit type.
	std::map<std::string, sf::Texture*>* texMap;

	//pointer to the tilemap
	tileMap* tileMapPtr;

	//runs at launch, loads the all the texture files needed for sprites
	//placed in gamestate for convenience
	std::map<std::string, sf::Texture*>* loadTextureFiles();

	//pointer to the camera
	Camera* cam;

	//drawMoveUI draws the blue highlighting for the squares that it is possible for the selected unit to move to
	void drawMoveUI(Unit *pUnit, int unitPosX, int unitPosY);

	//pointer to the currently selected unit. can be nullptr if no unit is selected
	Unit* selectedUnit;

	bool movementMode;

	bool keyPressed;
	bool lshiftDown;
	int counter;

	//A list of all the blue highlight squares that indicate it is possible for the selected unit to move to that square
	std::set<std::pair<int, int>>* moveList;
	std::set<std::pair<int, int>>* enemyList;


	int selectedX;
	int selectedY;

	sf::Text* p1;
	sf::Text* p2;
	sf::Text* pTeam1;
	sf::Text* pTeam2;
	sf::Text* healthText;


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

	int getCurrentPlayer();

	sf::Text* & getP1Text();
	sf::Text* & getP2Text();
	sf::Text *& GameState::getHealthText();
	sf::Text* & getP1TeamText();
	sf::Text* & getP2TeamText();
	void attack(Unit*& attacker, Unit*& target);
	void die(Unit*& in_unit);

	void endTurn();
	void setPlayerCount(int in_playerCount = 2);

	void setTileSize(int newSize);

	//void GameState::attack(Unit* unit1, Unit* unit2);
	void GameState::action();

	Cursor* getCursor();
	Camera* getCamera();

	std::map<std::string, sf::Texture*>* getTexMap();
};