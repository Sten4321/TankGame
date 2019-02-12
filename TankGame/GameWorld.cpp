#include "GameWorld.h"

//Updates the game
void GameWorld::Update()
{

}

void GameWorld::Remove()
{
}

void GameWorld::Add()
{
}

//Draws out the program
void GameWorld::Draw()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	//Clear the screen (fill it with black color)
	window->clear(sf::Color(0, 255, 255, 255));
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
		Remove();
		Add();
	}
}

//Constructor starts the gameloop and sets the window used for drawing
GameWorld::GameWorld(sf::RenderWindow * window)
{
	this->window = window;
	GameLoop();
}


GameWorld::~GameWorld()
{
	std::vector<GameObject*>::iterator it;
	for (it = gameobjects->begin(); it != gameobjects->end(); it++)/*call deconstructer on all components,
																 to make sure it is deleted and no causing memory leaks*/
	{
		delete (*it);
	}
	gameobjects->clear();
	delete gameobjects;//don't know if these 2 lines are necerssary
	gameobjects = nullptr;
}
