#pragma once
#include "UI.h"

class Cursor : public UI {
private:


public:
	Cursor(void);
	Cursor(sf::Texture* inTex);
	void update(KeyState &curState);
};