//An engine object contains the main game loop and is where objects are rendered to the screen

#pragma once
#include "header/GameState.h"
#include "header/EventManager.h"
#include "header/Camera.h"
#include "header/Menu.h"
#include <fstream>


class Engine {

public:

	Engine();
	~Engine();

	void drawSprites(Camera* cam);
	void drawUIElements();
	void drawUIList(std::list<UI*>* list);

	void updateUI(KeyState &keys);

	void run();

private:

	//tileSize is the amount of pixels on one side of the square tiles that make up the map
	int tileSize = 100; 

	std::map<std::string, std::string*> loadConfigFile();

	GameState* state;
	sf::RenderWindow* window;
	Menu* mainMenu;

	

};