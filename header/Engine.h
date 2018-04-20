//An engine object contains the main game loop and is where objects are rendered to the screen

#pragma once
#include "header/GameState.h"
#include "header/EventManager.h"
#include <fstream>


class Engine {

public:

	Engine();
	~Engine();

	void drawSprites();
	void drawUIElements();
	void updateUI(KeyState &keys);
	void addSprite(sf::Sprite &newSprite);
	void removeSprite(sf::Sprite* &deleteSprite);
	void run();

private:


	std::map<std::string, std::string*> loadConfigFile();

	GameState state;
	sf::RenderWindow* window;

	int tileSize = 100; //change this size later
	

};