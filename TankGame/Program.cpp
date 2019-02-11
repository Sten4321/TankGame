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
	if (window == NULL)//was the window created?
	{
		cout << "Failed to start window";
		return -1;
	}
	window->setFramerateLimit(60);//sets the fps to a limmit of 60

	GameWorld * gameWorld = new GameWorld(window);//creates the gameworld and begins the gameloop.

	delete gameWorld;//not necessary but done for the sake of virsualisation to make sure its there
	return 0;
}