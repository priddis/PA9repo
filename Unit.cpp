//unit abstract class
//reduceHealthAttacked() not defined below because it is pure virtual
//tw 4/18/18

#include "header/Unit.h"

Unit::Unit(sf::Texture*& in_texture, int in_team, float in_scale)
	: sf::Sprite(*in_texture)
{
	this->setTeam(in_team);
	this->setScale(in_scale, in_scale);
}

Unit::~Unit()
{
	//no dynam mem ..yet at least
}

//****getters
int Unit::getMaxHealth() {
	return maxHealth;
}

int Unit::getCurrentHealth() {
	return currentHealth;
}

int Unit::getAttackDamage() {
	return attackDamage;
}

int Unit::getAttackRange() {
	return attackRange;
}

int Unit::getCurrentTravelRange() {
	return currentTravelRange;
}

int Unit::getMaxTravelRange() {
	return maxTravelRange;
}

int Unit::getCost() {
	return cost;
}

int Unit::getSight() {
	return sight;
}

int Unit::getTeam() {
	return team;
}

std::string Unit::getUnitType() {
	return unitType;
}

int Unit::getDefensiveModifier(std::string in_unit) {
	return defensiveModifier.at(in_unit);
}

//****setters
void Unit::setMaxHealth(int in_health) {
	maxHealth = in_health;
}

void Unit::setCurrentHealth(int in_health) {
	if (in_health <= 0) currentHealth = 0;
	else currentHealth = in_health;
}

void Unit::setAttackDamage(int in_damage) {
	attackDamage = in_damage;
}

void Unit::setAttackRange(int in_range) {
	attackRange = in_range;
}

void Unit::setCurrentTravelRange(int in_range) {
	currentTravelRange = in_range;
}

void Unit::setSight(int in_sight) {
	sight = in_sight;
}

void Unit::setCost(int in_cost) {
	cost = in_cost;
}

void Unit::setTeam(int in_team) {
	team = in_team;
}

//protected

void Unit::setMaxTravelRange(int in_range) {
	maxTravelRange = in_range;
}

void Unit::setUnitType(std::string in_unitType) {
	unitType = in_unitType;
}

//defensive modifier pure virtual