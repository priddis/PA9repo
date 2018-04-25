//An engine object contains the main game loop and is where objects are rendered to the screen

#include "header/Engine.h"
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
	if (settings.count("ResY")) {
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
	else{
		window = new sf::RenderWindow(sf::VideoMode(ResolutionX, ResolutionY), "SFML works!");
	}
	window->setFramerateLimit(60);

	state = new GameState(tileSize, ResolutionX, ResolutionY);

	
}

Engine::~Engine()
{
	delete state;
}

//iterates through the list of sprites and draws each one to the screen
void Engine::drawSprites(Camera* cam)
{

	tileInfo* tempTileInfo = nullptr;
	Terrain* tempTerrain = nullptr;
	Unit* tempUnit = nullptr;
	int x = 0;
	int y = 0;
	//getting access to the tile map that resides in gamestate. ref!
	tileMap* tileMapPtr = state->getTileMap();

	for (x = 0; x < cam->getCamWidth(); x++) {

		for (y = 0; y < cam->getCamHeight(); y++) {
			//printing for testing purposes
			//std::cout << i + cam->getCamX() << " " << j + cam->getCamY() << std::endl;

			tempTileInfo = tileMapPtr->getTileInfo(x + cam->getCamX(), y + cam->getCamY());
			tempTerrain = tempTileInfo->getTerrainPtr();
			tempUnit = tempTileInfo->getUnitPtr();
			if (tempTerrain != nullptr) {
				tempTerrain->setPosition(x  * tileSize, y * tileSize);
				window->draw(*tempTerrain);
			}
			if (tempUnit != nullptr) {
				tempUnit->setPosition(x * tileSize, y * tileSize);
				window->draw(*tempUnit); 
			}
			//may be unnecessary. check. wont hurt though
			tempTileInfo = nullptr;
			tempTerrain = nullptr;
			tempUnit = nullptr;
		}
	}
}

//iterates through the list of UI elements and draws each one to the screen
void Engine::drawUIElements()
{
	for (UI* element : *(state->getUIElements())) {
		window->draw(*element);
	}

}

//iterates through the list of UI elements and draws each one to the screen
void Engine::updateUI(KeyState &keys)
{
	for (UI* element : *state->getUIElements()) {
		element->update(keys, state->getCamera());
	}
}

//void keyPresses() {
//	bool spacePressed = false; // needed for a single press
//	while (getKe.space && !spacePressed) {
//		state->action();
//		spacePressed = true;
//	}
//}

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
				EventManager::handleEvent(event,state->getKeys());
			}
			
		}
		//clear the screen in order to render the next frame
		window->clear();
		state->update();
		drawSprites(state->getCamera());
		updateUI(state->getKeys());
		drawUIElements();
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
