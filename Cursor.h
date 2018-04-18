#pragma once
#include "UI.h"

class Cursor : public UI {
private:

public:
	Cursor(void);
	
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	virtual void update();
};