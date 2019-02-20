#pragma once
#ifndef GAMEWORLD
#define GAMEWORLD
#include "Generater.h"
#include "TextureManager.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Rock.h"
#include "Collider.h"
#define GetxSize(X) texmgr.getRef(X).getSize().x
#define GetySize(X) texmgr.getRef(X).getSize().y

class GameWorld
{
private:
	sf::RenderWindow * window = nullptr;
	void GameLoop();
	void Draw();
	void Update(sf::Time deltaTime);
	void Remove();
	void Add();
	void LoadTextures();
	sf::Sprite BackGround;
	static std::vector<GameObject*> * gameobjects;
	static std::vector<GameObject*> * addGameobjects;
	static std::vector<GameObject*> * removeGameobjects;
	/*Vector containers since i need a container of unspecified size,
	that will grow (or shrink) as needed*/
public:
	GameWorld(sf::RenderWindow * window);
	~GameWorld();
	TextureManager& texmgr = TextureManager::getInstance();
	Generater & gen = Generater::getInstance();
	static void AddGameObject(GameObject* object);
	static void AddRemoveGameObject(GameObject* object);
	static std::vector<Collider*> * colliders;
};

#endif