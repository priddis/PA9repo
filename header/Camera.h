#pragma once
struct coordinates {

	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;
	int width;
	int height;

};

class Camera {

private:
	coordinates pos;
	int maxWidth;
	int maxHeight;

public:

	//inWidth and inHeight are the number of tiles in each direction the camera should display
	Camera(int inWidth, int inHeight, int maxWidth, int maxHeight);
	~Camera();

	void moveCamera(int xOffset, int yOffset;

};