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
using namespace std;
using namespace sf;

class GameWorld
{
private:
	RenderWindow * window = nullptr;
	void GameLoop();
	void Draw();
	void Update();

public:
	GameWorld(RenderWindow * window);
	~GameWorld();
};

#endif