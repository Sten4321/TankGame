#pragma once
#ifndef TRANSFORM
#define TRANSFORM
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "Component.h"

class GameObject;

class Transform : public Component
{
public:
	Transform(sf::Vector2f position = sf::Vector2f(0, 0), GameObject * gamobject = nullptr);
	~Transform();
	bool canMove = true;
	sf::Vector2f position;
	void Translate(sf::Vector2f translation);
};

#endif