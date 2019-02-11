#include "GameWorld.h"
using namespace sf;

void GameWorld::Update()
{

}

void GameWorld::Draw()
{


	//Clear the screen (fill it with black color)
	window->clear(Color(0,255,255,255));
	//Display window contents on screen
	window->display();
}

void GameWorld::GameLoop()
{
	while (window->isOpen())
	{
		Update();
		Draw();
	}
}

GameWorld::GameWorld(RenderWindow * window)
{
	this->window = window;
	GameLoop();
}


GameWorld::~GameWorld()
{
}
