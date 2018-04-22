#include "header/tileInfo.h"
#include <iostream>

tileInfo::tileInfo(Unit* in_unit, Terrain* in_terrain)
{
	unitPtr = in_unit;
	terrainPtr = in_terrain;
}

tileInfo::~tileInfo()
{
	//right now alloc only takes place in reading in map.
	//if we make adding units in game remember to check if the ptr is pting to a unit first
	//before assigning it to new dynamic mem
	//also, two unitPtrs should never point to the same unit!

	if (unitPtr != nullptr) delete unitPtr;
	if (terrainPtr != nullptr) delete terrainPtr;
	std::cout << "tileInfo deleted!" << std::endl;
}


void tileInfo::setUnitPtr(Unit* in_unit) {
	unitPtr = in_unit;
}

void tileInfo::setTerrainPtr(Terrain* in_terrain) {
	terrainPtr = in_terrain;
}

Unit* tileInfo::getUnitPtr() {
	return unitPtr;
}

Terrain* tileInfo::getTerrainPtr() {
	return terrainPtr;
}