#pragma once
#ifndef TOWER
#define TOWER
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Window.hpp"
#include "Component.h"
#include "IUpdatable.h"
#include "ICollideble.h"
#include "Transform.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))

class Tower :public Component, public IUpdatable, public ICollideble
{
private:
	const double PI = 3.1415927;
	int health;
	float attackRate;
	float attackRange;
	float shootTimeStamp = 0;
	int spread;
	float timePassed = 0;
	void Shoot();
	Collider* FindEnemiesInRange();
	bool Intersects(sf::Vector2f other, float radius);
	sf::CircleShape AttackRadius();
	float GetDegreesFromDestination(sf::Vector2f destinationVec);
	void AddAnimations();
	void Die();
public:
	Tower(GameObject * gameObject = nullptr, int health = 320, float attackRate = 3, float attackRange = 200, int spread = 4);
	~Tower();

	void SetHealth(int healthChange);

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;

	// Inherited via ICollideble
	virtual void CollisionEnter(Collider other) override;
	virtual void CollisionExit(Collider other) override;
	virtual void CollisionStay(Collider other) override;
};

#endif