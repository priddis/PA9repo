#pragma once
#include <list>
#include <SFML/Graphics.hpp>



struct keyState {
	bool lmb;
	bool rmb;
	bool a;

};

class GameState{

private:

	//list of sprites to display to the screen
	std::list<sf::Sprite>* spriteList;

	//list of keys currently held down
	keyState keys;


public:
	GameState();
	~GameState();

	std::list<sf::Sprite>* & getSprites();




};