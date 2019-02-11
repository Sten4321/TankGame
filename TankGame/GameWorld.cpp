#include "GameWorld.h"
using namespace sf;

//Updates the game
void GameWorld::Update()
{

}

//Draws out the program
void GameWorld::Draw()
{


	//Clear the screen (fill it with black color)
	window->clear(Color(0, 255, 255, 255));
	//Display window contents on screen
	window->display();
}

//Gameloop handles what happens
void GameWorld::GameLoop()
{
	while (window->isOpen())
	{
		Update();
		Draw();
	}
}

//Constructor starts the gameloop and sets the window used for drawing
GameWorld::GameWorld(RenderWindow * window)
{
	this->window = window;
	GameLoop();
}


GameWorld::~GameWorld()
{
}
