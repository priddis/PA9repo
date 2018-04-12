//An engine object contains the main game loop and is where objects are rendered to the screen

#include "header/Engine.h"


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
		GameState state;

		while (window->pollEvent(event))
		{
			//events related to the window are handled outside of eventmanager
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			else {
				EventManager::handleEvent(event,state.getKeys());
			}
		}
		//clear the screen in order to render the next frame
		window->clear();

		drawSprites();
		window->display();
	}
}