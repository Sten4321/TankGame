#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "GameWorld.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")//no console window

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tank Game");
	if (window == NULL)//was the window created?
	{
		std::cout << "Failed to start window";
		return -1;
	}
	window->setFramerateLimit(60);//sets the fps to a limmit of 60

	GameWorld * gameWorld = new GameWorld(window);//creates the gameworld and begins the gameloop.

	delete gameWorld;//not necessary but done for the sake of virsualisation to make sure its there
	return 0;
}