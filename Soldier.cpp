#include "header/Soldier.h"

Soldier::Soldier(sf::Texture* in_texture, int in_team, float in_scale)
	: Unit::Unit(in_texture, in_team, in_scale)
{
	setTeam(in_team);

	setMaxHealth(5);
	setCurrentHealth(5);
	setAttackDamage(3);
	setAttackRange(3);
	setMaxTravelRange(6);
	setCurrentTravelRange(6);
	setSight(3);
	setCost(100);
	setUnitType("Soldier");

	setDefensiveModifier();
}

Soldier::~Soldier()
{
}
/*
void Soldier::reduceHealthAttacked(int in_damage, std::string attackerUnitType) {
	//switch doesn't work with strings. this may seem messy.
	if (attackerUnitType == "XXXX") setCurrentHealth(in_damage - 1);
	else if (attackerUnitType == "XXXXX") setCurrentHealth(in_damage + 2);
	else    setCurrentHealth(in_damage);
}
*/

void Soldier::setDefensiveModifier() {
	defensiveModifier.insert(std::pair<std::string, int>("Tank", -1));

}