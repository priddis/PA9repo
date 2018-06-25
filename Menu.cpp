#include "header/Menu.h"
Menu::Menu() {
	open = false;
}
Menu::~Menu() {

}

std::list<UI*>* & Menu::getMenuUI()
{
	return menuUiList;
}

void Menu::update(KeyState & keys)
{
}

bool Menu::isOpen()
{
	return open;
}

