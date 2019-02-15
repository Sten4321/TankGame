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
#include "Transform.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))

class Player :public Component, public IUpdatable
{
private:
	int health = 100;
	float rotation = 0;
	int movespeed = 120;
	float rotateSpeed = 1.7f;
	const double PI = 3.1415927;
	void AddAnimations();
public:
	Player(GameObject * gameobject = nullptr);
	~Player();

	int GetHealth();
	void SetHealth(int healthChange);

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;

	void Die();
	sf::Vector2f Movement(sf::Vector2f translation);
	void Rotate();
	sf::Vector2f RotateVector(sf::Vector2f vector);
	void TranslateMovement(sf::Vector2f Translation, sf::Time deltaTime);
};

#endif