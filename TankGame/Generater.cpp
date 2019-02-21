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
	PlayerObj->AddComponent(new SpriteRenderer(PlayerObj, "PlayerSprite", sf::IntRect(0, 0, 28, 40), 0.0f));
	PlayerObj->AddComponent(new Player(PlayerObj));
	PlayerObj->AddComponent(new Collider(PlayerObj));
	GameWorld::AddGameObject(PlayerObj);
}

//Creates a Rock
void Generater::GenerateRock(sf::Vector2f position, int xSize, int ySize)
{
	GameObject * rock = new GameObject(position);
	rock->AddComponent(new SpriteRenderer(rock, "Rock1", sf::IntRect(0, 0, xSize, ySize), 0.0f));
	rock->AddComponent(new Rock(rock));
	rock->AddComponent(new Collider(rock));
	GameWorld::AddGameObject(rock);
}

//Makes a Small Bullet
void Generater::GenerateBulletSmall(sf::Vector2f position, float dirRotation)
{
	GameObject * bullet = new GameObject(position);
	bullet->AddComponent(new SpriteRenderer(bullet, "BasicBullet", sf::IntRect(0, 0, 1, 22), 0.0f));
	bullet->AddComponent(new Bullet(bullet, 65, 800, dirRotation, 0.5f));
	bullet->AddComponent(new Collider(bullet));
	GameWorld::AddGameObject(bullet);
}

//Makes a Big bullet
void Generater::GenerateBulletBig(sf::Vector2f position, float dirRotation)
{
	GameObject * bullet = new GameObject(position);
	bullet->AddComponent(new SpriteRenderer(bullet, "BiggerBullet", sf::IntRect(0, 0, 3, 22), 0.0f));
	bullet->AddComponent(new Bullet(bullet, 190, 700, dirRotation, 0.8f));
	bullet->AddComponent(new Collider(bullet));
	GameWorld::AddGameObject(bullet);
}

//Makes a Tower
void Generater::GenerateTower(sf::Vector2f position)
{
	GameObject * tower = new GameObject(position);
	tower->AddComponent(new SpriteRenderer(tower, "TowerBasic", sf::IntRect(0, 0, 32, 32), 0.0f));
	tower->AddComponent(new Tower(tower, 320, 1.0f, 200.0f, 4));
	tower->AddComponent(new Collider(tower));
	GameWorld::AddGameObject(tower);
}