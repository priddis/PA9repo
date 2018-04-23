#pragma once
#include "Unit.h"

class Soldier :
	public Unit
	{
	public:
		Soldier(sf::Texture* in_texture, int in_team, float in_scale);
		virtual ~Soldier(); //no dynam mem

						 //add any unique functions for a tank here..
		void reduceHealthAttacked(int in_damage, std::string attackerUnitType);
	};
