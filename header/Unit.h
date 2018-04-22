//unit abstract class
//reduceHealthAttacked() is pure virtual
//tw 4/18/18

#pragma once
#include <SFML/Graphics.hpp>

class Unit :
	public sf::Sprite
{
private:
	//maxhealth and current health for extensibility. health packs? visual of a health bar decreasing until death? game design questions for later
	int maxHealth;
	int currentHealth;
	int attackDamage;
	int attackRange;
	int travelRange;
	int sight;
	int cost;
	int team;

public:
	//all units take a starting texture. scale will most likely be necessary, but will have a default val of 1 until we know appropriate size.
	//team is always needed upon initialization
	Unit(sf::Texture* in_texture, int in_team, float in_scale = 1);
	virtual ~Unit();

	//future game design ideas
	//selectionSound() like "sir!" or "yeah boss?"
	//attackSound(); //unique sounds for units when they attack
	//attackTexture() //explosion texture overlayed over enemy unit during attack?

	//super effective / not very effective depending on unit. better solution than passing a string? but this will work
	//for example, tank shoots an infantry.. not very effective. tank damage is 5 normally, - 1 because its shooting at an infantry
	virtual void reduceHealthAttacked(int in_damage, std::string attackerUnitType) = 0;

	//****getters
	int getMaxHealth();
	int getCurrentHealth();
	int getAttackDamage();
	int getAttackRange();
	int getTravelRange();
	int getCost();
	int getSight();
	int getTeam();

	//****setters
	void setMaxHealth(int in_health); 
	void setCurrentHealth(int in_health);
	void setAttackDamage(int in_damage);
	void setAttackRange(int in_range);
	void setTravelRange(int in_range);
	void setSight(int in_sight);
	void setCost(int in_cost);
	void setTeam(int in_team);
};