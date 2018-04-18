
#pragma once
//#include <Sprite.hpp> this is not working. using below include instead.
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
	//all units take a starting texture
	Unit(sf::Texture* in_texture);
	~Unit();

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

