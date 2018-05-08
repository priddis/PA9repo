
#pragma once
#include "header/Tank.h"
#include "header/Road.h"

class tileInfo
{
private:
	Unit* unitPtr;
	Terrain* terrainPtr;

public:
	tileInfo(Unit* in_unit = nullptr, Terrain* in_terrain = nullptr);
	~tileInfo();

	void setUnitPtr(Unit*);
	void setTerrainPtr(Terrain*);

	Unit* & getUnitPtr();
	Terrain* getTerrainPtr();

};