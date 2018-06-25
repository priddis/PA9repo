#pragma once
#include <list>
#include "header/UI.h"
class Menu {

	bool open;

private:
	std::list<UI*>* menuUiList;
	

public:

	Menu();
	~Menu();
	std::list<UI*>* & getMenuUI();
	void update(KeyState & keys );

	bool isOpen();
};