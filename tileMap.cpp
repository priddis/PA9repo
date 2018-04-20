#include "header/tileMap.h"

tileMap::tileMap(std::map<std::string, sf::Texture*>& textureMap, int in_scale)
{
	//error here. may go away once
	textureMapPtr = *textureMap;
	scale = in_scale;
}

tileMap::~tileMap()
{
}

tileInfo* tileMap::getTileInfo(int x, int y) {
	return map[x][y];
}

bool tileMap::openMap(std::string in_fileName)
{
	bool success = false;
	Unit* unitPMem = nullptr;
	Terrain* terrainPMem = nullptr;
	tileInfo* tileInfoPMem = nullptr;

	std::string mapFilePath = "maps/" + in_fileName;
	std::string x, y, in_unitType, in_terrainType, in_team;
	std::ifstream fileOpener;
	fileOpener.open(mapFilePath);
	if (fileOpener)//checking to make sure file is open
	{
		success = true;
		//first line has the x and y vals for total map size. here we set vector size
		getline(fileOpener, x, ',');
		//could have my x's and y's mixed up, but they will be consistent. set one dimension to x
		map.resize(atoi(x.c_str()));
		//get y val
		getline(fileOpener, y, ',');
		//go down x dimension and set each vector's size to y
		for (int i = 0; i < atoi(x.c_str()); ++i) map[i].resize(atoi(y.c_str()));
		//now for the tileInfo lines
		while (!fileOpener.eof())
		{
			getline(fileOpener, x, ',');
			getline(fileOpener, y, ',');

			getline(fileOpener, in_unitType);
			getline(fileOpener, in_team, ',');
			allocUnitObj(unitPMem, in_unitType, in_team, scale);

			getline(fileOpener, in_terrainType, ',');
			allocTerrainObj(terrainPMem, in_terrainType, scale);

			tileInfoPMem = new tileInfo(unitPMem, terrainPMem);

			setTileInfo(atoi(x.c_str()), atoi(y.c_str()), tileInfoPMem);
		}
	}

	fileOpener.close();
	return success;
}

bool tileMap::allocUnitObj(Unit*& in_unitPMem, std::string in_unitType, std::string team, int scale) {
	in_unitPMem = nullptr;
	bool success = false;

	if (in_unitType == "Tank") {
		in_unitPMem = new Tank((*textureMapPtr)["Tank"], atoi(team.c_str()), scale);
		
	}
	//else ifs go here for additional units

	if (in_unitPMem != nullptr) success = true;
	return success;
}

bool tileMap::allocTerrainObj(Terrain*& in_terrainPMem, std::string in_terrainType, int scale) {
	in_terrainPMem = nullptr;
	bool success = false;

	if (in_terrainType == "Road") {
		in_terrainPMem = new Road((*textureMapPtr)["Tank"], scale);
	}
	//else ifs go here for additional terrains
	
	if (in_terrainPMem != nullptr) success = true;
	return success;
}

void tileMap::setTileInfo(int x, int y, tileInfo* tileInfoPMem){
	map[x][y] = tileInfoPMem;
}