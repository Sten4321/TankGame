#include "Generater.h"
#include "GameWorld.h"


Generater::Generater()
{
}


Generater::~Generater()
{
}

//Creates a playerObject
void Generater::GeneratePlayer(sf::Vector2f position)
{
	GameObject * PlayerObj = new GameObject(position);
	PlayerObj->AddComponent(new SpriteRenderer(PlayerObj, "PlayerSprite", sf::IntRect(0, 0, 28, 40), 30.0f));
	PlayerObj->AddComponent(new Player(PlayerObj));
	PlayerObj->AddComponent(new Collider(PlayerObj));
	GameWorld::AddGameObject(PlayerObj);
}

//Creates a Rock
void Generater::GenerateRock(sf::Vector2f position, float xSize, float ySize)
{
	GameObject * rock = new GameObject(position);
	rock->AddComponent(new SpriteRenderer(rock, "Rock1", sf::IntRect(0, 0, xSize, ySize), 0.0f));
	rock->AddComponent(new Rock(rock));
	rock->AddComponent(new Collider(rock));
	GameWorld::AddGameObject(rock);
}
