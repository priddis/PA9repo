//not much needed for this class. derived from unit. most of the magic is the tank specific characteristic values being set in the constructor
//also its very effective / not very effective damage taken is the  reduceHealthAttacked() defined below
//this is the only concrete unit defined thus far
//tw 4/18/18

#include "header/Tank.h"

Tank::Tank(sf::Texture*& in_texture, int in_team, float in_scale)
	: Unit::Unit(in_texture, in_scale, in_team)
{
	setTeam(in_team);

	setMaxHealth(10);
	setCurrentHealth(10);
	setAttackDamage(5);
	setAttackRange(3);
	setTravelRange(2);
	setSight(3);
	setCost(250);
}

Tank::~Tank(){}

void Tank::reduceHealthAttacked(int in_damage, std::string attackerUnitType) {
	//switch doesn't work with strings. this may seem messy.
	if		(attackerUnitType == "Soldier") setCurrentHealth(in_damage - 1);
	else if (attackerUnitType == "Bazookaman") setCurrentHealth(in_damage + 2);
	else    setCurrentHealth(in_damage);
}