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
	std::vector<GameObject*> * gameobjects = new std::vector<GameObject*>;
	std::vector<GameObject*> * addGameobjects = new std::vector<GameObject*>;
	std::vector<GameObject*> * removeGameobjects = new std::vector<GameObject*>;
	/*Vector since i need a container of unspecified size,
	that will grow (or shrink) as needed*/
public:
	GameWorld(sf::RenderWindow * window);
	~GameWorld();
	TextureManager& texmgr = TextureManager::getInstance();
};

#endif