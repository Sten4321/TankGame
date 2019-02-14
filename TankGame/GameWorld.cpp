#include "GameWorld.h"

//Loads Textures into the game
void GameWorld::LoadTextures()
{
	texmgr.loadTexture("PlayerSprite", "Data/PlayerTank.png");
	texmgr.loadTexture("Background", "Data/Background.png");
	texmgr.loadTexture("Error", "Data/Error.png");
}

//Removes Objects from the game
void GameWorld::Remove()
{
	std::vector<GameObject*>::iterator it;
	for (it = removeGameobjects->begin(); it != removeGameobjects->end(); it++)
	{
		//TODO: Delete objects
	}
	removeGameobjects->clear();
}

//Adds objects to the game
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

//Updates the game
void GameWorld::Update(sf::Time deltaTime)
{
	std::vector<GameObject*>::iterator it;
	for (it = gameobjects->begin(); it != gameobjects->end(); it++)
	{
		(*it)->Update(deltaTime);
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

	//BackGround
	window->draw(BackGround);

	//Draw here
	std::vector<GameObject*>::iterator it;
	for (it = gameobjects->begin(); it != gameobjects->end(); it++)
	{
		(*it)->Draw(window);
	}

	//Display window contents on screen
	window->display();
}

//Gameloop handles what happens
void GameWorld::GameLoop()
{
	sf::Clock deltaClock;
	while (window->isOpen())
	{
		sf::Time deltaTime = deltaClock.getElapsedTime();
		deltaClock.restart();
		Update(deltaTime);
		Draw();
		Remove();
		Add();
	}
}

//Constructor starts the gameloop and sets the window used for drawing
GameWorld::GameWorld(sf::RenderWindow * window)
{
	this->window = window;
	LoadTextures();
	BackGround.setTexture(texmgr.getRef("Background"));


	GameObject * PlayerObj = new GameObject(sf::Vector2f(250, 250));
	PlayerObj->AddComponent(new SpriteRenderer(PlayerObj, "PlayerSprite", 30.f));
	PlayerObj->AddComponent(new Player(PlayerObj));
	addGameobjects->push_back(PlayerObj);

	GameLoop();
}


GameWorld::~GameWorld()
{
	if (gameobjects)
	{
		std::vector<GameObject*>::iterator it;
		for (it = gameobjects->begin(); it != gameobjects->end(); it++)
		{
			delete (*it);
		}
		gameobjects->clear();
	}
}
