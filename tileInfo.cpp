#include "header/tileInfo.h"

tileInfo::tileInfo(Unit* in_unit, Terrain* in_terrain)
{
	unitPtr = in_unit;
	terrainPtr = in_terrain;
}

tileInfo::~tileInfo()
{
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