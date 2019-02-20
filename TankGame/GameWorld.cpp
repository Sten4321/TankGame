#include "GameWorld.h"

std::vector<GameObject*> * GameWorld::gameobjects = new std::vector<GameObject*>;
std::vector<GameObject*> * GameWorld::addGameobjects = new std::vector<GameObject*>;
std::vector<GameObject*> * GameWorld::removeGameobjects = new std::vector<GameObject*>;

//Loads Textures into the game
void GameWorld::LoadTextures()
{
	texmgr.loadTexture("PlayerSprite", "Data/PlayerTank.png");
	texmgr.loadTexture("Background", "Data/Background.png");
	texmgr.loadTexture("Error", "Data/Error.png");
	texmgr.loadTexture("Rock1", "Data/Rock1.png");
	texmgr.loadTexture("Rock2", "Data/Rock2.png");
}

//Removes Objects from the game
void GameWorld::Remove()
{
	if (removeGameobjects->size() > 0)
	{
		for (auto it = gameobjects->begin(); it != gameobjects->end(); )
		{
			if (std::find(removeGameobjects->begin(), removeGameobjects->end(), *it) != removeGameobjects->end())
			{
				delete(*it);
				it = gameobjects->erase(it);
			}
			else
			{
				++it;
			}
		}
		//std::vector<GameObject*>::iterator it;
		//for (it = removeGameobjects->begin(); it != removeGameobjects->end(); it++)
		//{
		//	//TODO: Delete objects
		//	gameobjects->erase((it));
		//}
		removeGameobjects->clear();
	}
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
		Add();
		Remove();
	}
}

//Constructor starts the gameloop and sets the window used for drawing
GameWorld::GameWorld(sf::RenderWindow * window)
{
	this->window = window;
	LoadTextures();
	BackGround.setTexture(texmgr.getRef("Background"));


	GameObject * PlayerObj = new GameObject(sf::Vector2f(250, 250));
	PlayerObj->AddComponent(new SpriteRenderer(PlayerObj, "PlayerSprite", sf::IntRect(0, 0, 28, 40), 30.0f));
	PlayerObj->AddComponent(new Player(PlayerObj));
	AddGameObject(PlayerObj);

	GameObject * rock = new GameObject(sf::Vector2f(400, 300));
	rock->AddComponent(new SpriteRenderer(rock, "Rock1", sf::IntRect(0, 0, GetxSize("Rock1"), GetySize("Rock1")), 0.0f));
	rock->AddComponent(new Rock(rock));
	AddGameObject(rock);

	GameLoop();
}


GameWorld::~GameWorld()
{
	//Not Working
	/*if (gameobjects)
	{
		std::vector<GameObject*>::iterator it;
		for (it = gameobjects->begin(); it != gameobjects->end(); it++)
		{
			delete (*it);
		}
		gameobjects->clear();
	}*/
}

//makes it so an object is prepared to be added
void GameWorld::AddGameObject(GameObject * object)
{
	addGameobjects->push_back(object);
}

void GameWorld::AddRemoveGameObject(GameObject * object)
{
	removeGameobjects->push_back(object);
}
