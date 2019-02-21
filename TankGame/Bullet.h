#pragma once
#ifndef BULLET
#define BULLET
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "IUpdatable.h"
#include "ICollideble.h"
#include "Transform.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))

class Bullet :public Component, public IUpdatable, public ICollideble
{
private:
	const double PI = 3.1415927;
	int bulletDmg;
	float rotation;
	float movementSpeed;
	float lifeSpan;
	float timeStamp = 0;
	float timePassed = 0;
	bool shouldDie = false;
	bool isRotated = false;
	void DestroyBullet();
	sf::Vector2f MoveForward(sf::Vector2f translation);
	sf::Vector2f RotateVector(sf::Vector2f translation);
	float GetDegreesFromDestination(sf::Vector2f translation);
	void TranslateMovement(sf::Vector2f translation, sf::Time deltaTime);
	void AddAnimations();
public:
	Bullet(GameObject * gameObject = nullptr, int bulletDmg = 65, float movementSpeed = 800, float rotation = 0, float lifeSpan = 0.5f);
	~Bullet();
	void BulletMovement(sf::Time deltaTime);
	void CheckIfBulletIsExpired(sf::Time deltaTime);

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;

	// Inherited via ICollideble
	virtual void CollisionEnter(Collider other) override;
	virtual void CollisionExit(Collider other) override;
	virtual void CollisionStay(Collider other) override;
};

#endif