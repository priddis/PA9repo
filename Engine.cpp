#include "Engine.h"
#include "EventManager.h"

Engine::Engine() {

	window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
}

Engine::~Engine()
{
}

//iterates through the list of sprites and draws each one to the screen
void Engine::drawSprites()
{
	for (sf::Sprite spr : *state.getSprites() ) {
		window->draw(spr);
	}
}

//run() contains the main game loop
//this is where events are handled through the event handler
//and this is where sprites are drawn
void Engine::run() {


	//main game loop. one pass through this is one frame
	while (window->isOpen())
	{

		sf::Event event;

		while (window->pollEvent(event))
		{

			if (event.type == sf::Event::Closed) {
				window->close();
			}
			else {
				EventManager::handleEvent(event);
			}
		}

		window->clear();
		drawSprites();
		window->display();
	}
}