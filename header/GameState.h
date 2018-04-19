/*A GameState object is an object that should contain 
all the game info for a particular frame.

Currently it contains a list for all the objects that need to be drawn to the screen, and a struct 
*/
 
#pragma once
#include <list>
#include <SFML/Graphics.hpp>
//included for units
#include "Tank.h"


struct KeyState {
	bool lmb;
	bool rmb;
	bool a;

};

class GameState{

private:

	//list of sprites to display to the screen
	//tw. think this is better as a list obj not a pointer to one. and hold ptr to sprite (sprites can be units or textures etc.. think PA8)
	std::list<sf::Sprite*> spriteList;

	//list of keys currently held down
	KeyState keys;

	//tw. how should we organize textures? i suppose for this project we wont have to many, and only one texture needs to be initialized for all units of that type.
	//we will know what file to associate at run time. so load all textures files when obj is created (from constructor?) ew
	sf::Texture* texture_tank;

public:
	GameState();
	~GameState();

	//tw. not sure why this is a pointer. changing it. changing container type to Sprite PTR
	std::list<sf::Sprite*>& getSprites();

	KeyState & getKeys();
};