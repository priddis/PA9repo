#pragma once
#include "UI.h"
#include "Camera.h"
class Cursor : public UI {
private:

	int tSize;


public:
	Cursor();
	Cursor(int tileSize, sf::Texture* inTex);
	void update(KeyState &curState, Camera* cam);
};