//An engine object contains the main game loop and is where objects are rendered to the screen

#pragma once
#include "header/GameState.h"
#include "header/EventManager.h"
#include "header/Camera.h"
#include <fstream>


class Engine {

public:

	Engine();
	~Engine();

	void drawSprites(Camera* cam);
	void drawUIElements();
	void updateUI(KeyState &keys);
	void addSprite(sf::Sprite &newSprite);
	void removeSprite(sf::Sprite* &deleteSprite);
	void run();

private:


	int tileSize = 100; //change this size later

	std::map<std::string, std::string*> loadConfigFile();

	GameState* state;
	sf::RenderWindow* window;

	

};