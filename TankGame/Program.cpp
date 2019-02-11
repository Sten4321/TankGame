#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "GameWorld.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Tank Game");
	window->setFramerateLimit(60);

	GameWorld * gameWorld = new GameWorld(window);

	delete gameWorld;
	return 0;
}