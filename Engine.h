#pragma once
#include "GameState.h"
#include "EventManager.h"

class Engine {

public:

	Engine();
	~Engine();

	void drawSprites();
	void addSprite(sf::Sprite &newSprite);
	void removeSprite(sf::Sprite* &deleteSprite);
	void run();

private:

	GameState state;
	sf::RenderWindow* window;
	

};