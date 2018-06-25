#pragma once
#include <list>
#include "header/UI.h"
class Menu {

	bool open;
	std::map<std::string, sf::Texture*>* menuTexMap;

private:
	std::list<UI*>* menuUiList;

	void loadMenuTexMap();

public:

	Menu();
	~Menu();
	std::list<UI*>* & getMenuUI();
	void update(KeyState & keys );


	bool isOpen();
};