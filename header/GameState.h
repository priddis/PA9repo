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
#include "KeyState.h"

class GameState{

private:

	//list of sprites to display to the screen
	std::list<sf::Sprite>* spriteList;
	std::vector<UI*>* uiList;

	bool currentPlayer;
	int turnCounter;
	int mapSizeX;
	int mapSizeY;

	//TileMap level;

	//struct of keys currently held down
	KeyState keys;

	std::map<std::string, sf::Texture*>* texMap;


	//runs at launch, loads the all the texture files needed for sprites
	//placed in gamestate for convenience
	std::map<std::string, sf::Texture*>* loadTextureFiles();


public:
	GameState();
	~GameState();

	void update();

	std::list<sf::Sprite>* & getSprites();
	std::vector<UI*>* & getUIElements();

	KeyState & getKeys();

	void endTurn();

	void GameState::attack(Unit* unit1, Unit* unit2);
};