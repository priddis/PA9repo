//An engine object contains the main game loop and is where objects are rendered to the screen

#pragma once
#include "header/GameState.h"
#include "header/EventManager.h"


class Engine {

public:

	Engine();
	~Engine();

	void drawSprites();
	void addSprite(sf::Sprite &newSprite);
	void removeSprite(sf::Sprite* &deleteSprite);

	void drawUI();
	void updateUI();
	void run();

private:

	GameState state;
	sf::RenderWindow* window;
	

};