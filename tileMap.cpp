#include "header/tileMap.h"

tileMap::tileMap(std::map<std::string, sf::Texture*>*& textureMap, int in_scale)
{
	//error here. may go away once
	textureMapPtr = textureMap;
	scale = in_scale;
}

tileMap::~tileMap()
{
	int x, y;
	for (x = 0; x < getMaxX(); x++) {

		for (y = 0; y < getMaxY(); y++) {
			//tileInfo should never be nullptr for an existing tileMap coordinate, but being safe
			if (map[x][y] != nullptr) {
				delete map[x][y];
			}
		}
	}
}

tileInfo*& tileMap::getTileInfo(int x, int y) {
	return map[x][y];
}

bool tileMap::openMap(std::string in_fileName)
{
	bool success = false;
	Unit* unitPMem = nullptr;
	Terrain* terrainPMem = nullptr;
	tileInfo* tileInfoPMem = nullptr;
	sf::Texture* unitTexPMem = nullptr;
	sf::Texture* terrainTexPMem = nullptr;


	std::string mapFilePath = "maps/" + in_fileName;
	std::string in_x, in_y, in_unitType, in_terrainType, in_team;
	int x, y = 0;
	std::ifstream fileOpener;
	fileOpener.open(mapFilePath);
	if (fileOpener)//checking to make sure file is open
	{
		success = true;
		//first line has the x and y vals for total map size. here we set vector size
		getline(fileOpener, in_x, ',');
		//save this val for future use
		maxX = atoi(in_x.c_str()); 
		//x max (1 based)
		map.resize(atoi(in_x.c_str()));
		//y max (1 based)
		getline(fileOpener, in_y); //no delim.. end of line
		//save this val for future use
		maxY = atoi(in_y.c_str());
		//go down x dimension and set each vector's size to y
		for (int i = 0; i < maxX; ++i) map[i].resize(maxY);
		//now for the tileInfo lines
		while (!fileOpener.eof())
		{	
			//get our x and y coords for inserting future tileInfo into our map
			getline(fileOpener, in_x, ',');
			x = atoi(in_x.c_str());
			getline(fileOpener, in_y, ',');
			y = atoi(in_y.c_str());

			//getting unit info and calling func to dynam alloc new unit. unitPMem pts to this once completed
			getline(fileOpener, in_unitType, ',');
			getline(fileOpener, in_team, ',');
			if (in_unitType != "") {
				unitTexPMem = textureMapPtr->at(in_unitType.c_str());
				allocUnitObj(unitPMem, unitTexPMem, in_unitType, atoi(in_team.c_str()), scale);
			}
			else unitPMem = nullptr;

			//getting unit info and calling func to dynam alloc new unit. unitPMem pts to this once completed
			getline(fileOpener, in_terrainType); //no delim end of line
			if (in_terrainType != "") {
				terrainTexPMem = textureMapPtr->at(in_terrainType.c_str());
				allocTerrainObj(terrainPMem, terrainTexPMem, in_terrainType, scale);
			}
			else terrainPMem = nullptr;

			//create new tile dynamically with our new unit and texture objects (if they exist.. null is an option too)
			tileInfoPMem = new tileInfo(unitPMem, terrainPMem);

			//insert the new tileInfo in the right coordinate in our map
			setTileInfo(x, y, tileInfoPMem);
		}
	}

	fileOpener.close();
	return success;
}

//as we add additional units. update functionality here!
bool tileMap::allocUnitObj(Unit*& in_unitPMem, sf::Texture*& texturePMem, std::string in_unitType, int team, int scale) {
	in_unitPMem = nullptr;
	bool success = false;

	if (in_unitType == "Tank") {
		in_unitPMem = new Tank(texturePMem, team, scale);
		
	}
	else if (in_unitType == "Soldier") {
		in_unitPMem = new Soldier(texturePMem, team, scale);
	}
	//additional else ifs go here for additional units
	//if its null or invalid/nonexistant unit then its a nullptr
	else in_unitPMem = nullptr;

	if (in_unitPMem != nullptr) success = true;
	return success;
}

bool tileMap::allocTerrainObj(Terrain*& in_terrainPMem, sf::Texture*& texturePMem, std::string in_terrainType, int scale) {
	in_terrainPMem = nullptr;
	bool success = false;

	if (in_terrainType == "Road") {
		in_terrainPMem = new Road(texturePMem, scale);
	}
	else if (in_terrainType == "Grass") {
		in_terrainPMem = new Grass(texturePMem, scale);
	}
	//else ifs go here for additional terrains
	//if its null or invalid/nonexistant unit then its a nullptr
	else in_terrainPMem = nullptr;

	if (in_terrainPMem != nullptr) success = true;
	return success;
}

void tileMap::setTileInfo(int x, int y, tileInfo* tileInfoPMem){
	map[x][y] = tileInfoPMem;
}

int tileMap::getMaxX() {
	return maxX;
}
int tileMap::getMaxY() {
	return maxY;
}