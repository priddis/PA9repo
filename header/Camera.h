#pragma once

//The coordinates struct is used to bind info about the camera position and size together
struct coordinates {

	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;
	int width;
	int height;

};

//the camera class is used to track which tiles need to be rendered
//this allows scrolling on maps bigger than what the screen can render
class Camera {

private:
	coordinates pos;
	int maxWidth;
	int maxHeight;

public:

	//inWidth and inHeight are the number of tiles in each direction the camera should display
	Camera(int inWidth, int inHeight, int maxWidth, int maxHeight);
	~Camera();

	void moveCamera(int xOffset, int yOffset);

	int getCamWidth();
	int getCamHeight();
	int getCamX();
	int getCamY();
	int getMaxX();
	int getMaxY();
};