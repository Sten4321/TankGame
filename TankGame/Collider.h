#pragma once
#ifndef COLLIDER
#define COLLIDER
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "IUpdatable.h"
#include "Transform.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))

class Collider :public Component, public IUpdatable
{
private:
	void RemoveCollider();
	bool Intersects(sf::CircleShape other);
public:
	Collider(GameObject * gameobject = nullptr);
	~Collider();
	bool doCollisionChecks = true;
	std::vector<Collider*> otherColliders = std::vector<Collider*>();
	std::vector<Collider*> removeOtherColliders = std::vector<Collider*>();
	sf::CircleShape CollisionBox();
	void CheckCollision();

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;
};

#endif