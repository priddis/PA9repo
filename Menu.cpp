#include "header/Menu.h"
void Menu::loadMenuTexMap()
{
	menuTexMap = new std::map<std::string, sf::Texture*>();

	menuTexMap->insert(std::pair<std::string, sf::Texture*>("title", new sf::Texture()));
	menuTexMap->at("title")->loadFromFile("assets/mainMenu/title_text.png");
}
Menu::Menu() {

	


	open = true;
	menuUiList = nullptr;
	menuUiList = new std::list<UI*>();

	loadMenuTexMap();

	UI* title = new UI(menuTexMap->at("title"));
	title->moveUI(100, 100);
	menuUiList->push_back(title);
}
Menu::~Menu() {
	delete menuTexMap;
}

std::list<UI*>* & Menu::getMenuUI()
{
	return menuUiList;
}

void Menu::update(KeyState & keys)
{
	if (keys.space) {
		open = false;
	}
}

bool Menu::isOpen()
{
	return open;
}

