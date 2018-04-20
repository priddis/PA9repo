//not much needed for this class. derived from unit. most of the magic is the tank specific characteristic values being set in the constructor
//also its very effective / not very effective damage taken is the  reduceHealthAttacked() defined below
//this is the only concrete unit defined thus far
//tw 4/18/18

#pragma once
#include "Unit.h"
class Tank :
	public Unit
{
public:
	Tank(sf::Texture* in_texture, int in_team, float in_scale);
	~Tank();

	//add any unique functions for a tank here..
	void reduceHealthAttacked(int in_damage, std::string attackerUnitType);
};