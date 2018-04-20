
#pragma once
#include <vector>
#include "tileInfo.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


class tileMap
{
private:
	std::map<std::string, sf::Texture*>* textureMapPtr;
	//keep those two >>'s seperate
	std::vector<std::vector<tileInfo*> > map; 
	int scale;

public:
	//takes a ref to the textureMap and will assign a local data mem ptr to it for use
	tileMap(std::map<std::string, sf::Texture*>& textureMap, int in_scale = 1);
	~tileMap();

	bool openMap(std::string in_fileName);
	bool allocUnitObj(Unit*& unitPMem, std::string in_unitType, std::string team, int scale);
	bool allocTerrainObj(Terrain*& terrainPMem, std::string in_terrainType, int scale);

	void setTileInfo(int x, int y, tileInfo* tileInfoPMem);
	tileInfo* getTileInfo(int x, int y);

};