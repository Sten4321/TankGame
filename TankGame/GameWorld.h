#pragma once
#ifndef GAMEWORLD
#define GAMEWORLD

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "SFML/Graphics.hpp"

#include "TextureManager.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Rock.h"
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
	static std::vector<GameObject*> * gameobjects/* = new std::vector<GameObject*>*/;
	static std::vector<GameObject*> * addGameobjects/* = new std::vector<GameObject*>*/;
	static std::vector<GameObject*> * removeGameobjects/* = new std::vector<GameObject*>*/;
	/*Vector since i need a container of unspecified size,
	that will grow (or shrink) as needed*/
public:
	GameWorld(sf::RenderWindow * window);
	~GameWorld();
	TextureManager& texmgr = TextureManager::getInstance();
	static void AddGameObject(GameObject* object);
	static void AddRemoveGameObject(GameObject* object);
};

#endif