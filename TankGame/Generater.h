#pragma once
#ifndef GENERATER
#define GENERATER

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Rock.h"
#include "Bullet.h"
#include "Collider.h"
#include "Tower.h"

class Generater
{
private:
	Generater();
	~Generater();
public:
	static Generater& getInstance()
	{
		static Generater instance; // Guaranteed to be destroyed.
										// Instantiated on first use.
		return instance;
	}
	Generater(Generater const&) = delete;
	void operator=(Generater const&) = delete;

	void GeneratePlayer(sf::Vector2f position = sf::Vector2f(500, 400));
	void GenerateRock(sf::Vector2f position = sf::Vector2f(3, 2), int xSize = 10, int ySize = 10);
	void GenerateBulletSmall(sf::Vector2f position = sf::Vector2f(500, 400), float dirRotation = 0);
	void GenerateBulletBig(sf::Vector2f position = sf::Vector2f(500, 400), float dirRotation = 0);
	void GenerateTower(sf::Vector2f position = sf::Vector2f(500, 400));
};

#endif