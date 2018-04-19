//An engine object contains the main game loop and is where objects are rendered to the screen

#include "header/Engine.h"
#include "entities/include_entities.h"
#include <string>
#include <fstream>

Engine::Engine() {

	
	std::map<std::string, std::string*> settings = loadConfigFile();

	//declaring window settings and setting their defaults in case they are not defined in config.txt
	int ResolutionX = 800;
	int ResolutionY = 800;

	bool Fullscreen = false;

	if (settings.count("ResX")) {
		ResolutionX = std::stoi(*settings.at("ResX"));
	}
	if (settings.count("RexY")) {
		ResolutionY = std::stoi(*settings.at("ResY"));
	}
	if (settings.count("Fullscreen")) {
		if ( *(settings.at("Fullscreen")) == "True") {
			Fullscreen = true;
		}
	}

	if (Fullscreen) {
		window = new sf::RenderWindow(sf::VideoMode(ResolutionX, ResolutionY), "SFML works!", sf::Style::Fullscreen);
	}
	window = new sf::RenderWindow(sf::VideoMode(ResolutionX, ResolutionY), "SFML works!");
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

	sf::Event event;

	//main game loop. one pass through this is one frame
	while (window->isOpen())
	{
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

//used for parsing the config file, returns a vector with pointers to the parsed settings
std::map<std::string,std::string*> Engine::loadConfigFile()
{
	std::ifstream fStrm("config.txt");
	std::string str;

	std::map<std::string, std::string*>*  settings = new std::map<std::string, std::string*>();

	while(std::getline(fStrm, str)){
		if (str.substr(0, 5) == "ResX=") {
			(*settings).insert(std::pair<std::string, std::string*>("ResX", new std::string(str.substr(5))));
		}
		if (str.substr(0, 5) == "ResY=") {
			(*settings).insert(std::pair<std::string, std::string*>("ResY", new std::string(str.substr(5))));
		}
		if (str.substr(0, 11) == "Fullscreen=") {
			(*settings).insert(std::pair<std::string, std::string*>("Fullscreen", new std::string(str.substr(11))));
		}

	}
	return *settings;
	



}
