#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

