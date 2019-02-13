#pragma once
#ifndef SPRITERENDERER
#define SPRITERENDERER
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "TextureManager.h"
#include "GameObject.h"

class SpriteRenderer :public Component, public IDrawable, public IUpdatable
{
private:
	sf::Sprite sprite;
	void UpdateDrawPos();
public:
	SpriteRenderer(GameObject * gamobject = nullptr, std::string spriteName = "Error", float rotation = 0);
	~SpriteRenderer();
	float rotation = 0;

	// Inherited via IDrawable
	virtual void Draw(sf::RenderWindow * window) override;

	//Implement acess to textures
	TextureManager& texmgr = TextureManager::getInstance();

	// Inherited via IUpdatable
	virtual void Update() override;
};

#endif