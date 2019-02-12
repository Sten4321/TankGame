#pragma once
#ifndef GAMEWORLD
#define GAMEWORLD

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Map.h"
#include "GameObject.h"
#include "SFML/Graphics.hpp"

class GameWorld
{
private:
	sf::RenderWindow * window = nullptr;
	void GameLoop();
	void Draw();
	void Update();
	void Remove();
	void Add();
	std::vector<GameObject*> * gameobjects = new std::vector<GameObject*>;
	/*Vector since i need a container of unspecified size,
	that will grow (or shrink) as needed*/
public:
	GameWorld(sf::RenderWindow * window);
	~GameWorld();
};

#endif