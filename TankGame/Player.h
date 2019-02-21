#pragma once
#ifndef PLAYER
#define PLAYER
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

class Player :public Component, public IUpdatable, public ICollideble
{
private:
	int maxhealth = 1000;
	int health = 1000;
	float rotation = 0;
	int movespeed = 120;
	float rotateSpeed = 1.7f;
	const double PI = 3.1415927;
	float timeStamp = 0;
	float timePassed = 0;
	float fireDelay = 1;
	void AddAnimations();
	void Shoot();
	void Die();
public:
	Player(GameObject * gameobject = nullptr);
	~Player();

	int GetHealth();
	void SetHealth(int healthChange);

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;

	sf::Vector2f Movement(sf::Vector2f translation);
	void Rotate();
	sf::Vector2f RotateVector(sf::Vector2f vector);
	void TranslateMovement(sf::Vector2f Translation, sf::Time deltaTime);

	// Inherited via ICollideble
	virtual void CollisionEnter(Collider other) override;
	virtual void CollisionExit(Collider other) override;
	virtual void CollisionStay(Collider other) override;
};

#endif