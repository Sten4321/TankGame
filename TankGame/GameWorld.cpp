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
	if (addGameobjects->size() > 0)
	{
		std::vector<GameObject*>::iterator it;
		for (it = addGameobjects->begin(); it != addGameobjects->end(); it++)
		{
			gameobjects->push_back(*it);
		}
		addGameobjects->clear();
	}
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
	GameObject * testObject = new GameObject();
	testObject->AddComponent(new SpriteRenderer(testObject));
	addGameobjects->push_back(testObject);

	this->window = window;
	GameLoop();
}


GameWorld::~GameWorld()
{
	for (int i = 0; i < gameobjects->size(); i++)
	{
		delete (*gameobjects)[i];
	}
	gameobjects->clear();
}
