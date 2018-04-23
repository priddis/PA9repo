#include "header/Camera.h"

//inWidth is the width of the camera, maxWidth is the width of the map
Camera::Camera(int inWidth, int inHeight, int inMaxWidth, int inMaxHeight)
{
	pos.topLeftX = 0;
	pos.topLeftY = 0;

	pos.bottomRightX = inWidth;
	pos.bottomRightY = inHeight;

	pos.width = inWidth;
	pos.height = inHeight;

	maxWidth = inMaxWidth;
	maxHeight = inMaxHeight;

}

void Camera::moveCamera(int xOffset, int yOffset)
{
	pos.topLeftX += xOffset;
	pos.bottomRightX += xOffset;

	//if the camera tries to move left of the farthest left tiles, then we reset the x positions of the camera
	//to be on the edge of the boundary
	if (pos.topLeftX < 0) {
		pos.topLeftX = 0;
		pos.bottomRightX = pos.width;
	}

	//same as above, but for the right most boundaries
	if (pos.bottomRightX >= maxWidth) {
		pos.bottomRightX = maxWidth ;
		pos.topLeftX = maxWidth - pos.width;
	}


	pos.topLeftY += yOffset;
	pos.bottomRightY += yOffset;


	//y components of above code
	if (pos.bottomRightY >= maxHeight) {
		pos.bottomRightY = maxHeight; 
		pos.topLeftY = maxHeight - pos.height ;
	}

	if (pos.topLeftY < 0) {
		pos.topLeftY = 0;
		pos.bottomRightY = pos.height;
	}
}

int Camera::getCamWidth()
{
	return pos.width;
}

int Camera::getCamHeight()
{
	return pos.height;
}

int Camera::getCamX()
{
	return pos.topLeftX;
}

int Camera::getCamY()
{
	return pos.topLeftY;
}

int Camera::getMaxX()
{
	return maxWidth;
}

int Camera::getMaxY()
{
	return maxHeight;
};

