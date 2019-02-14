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
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))

class SpriteRenderer :public Component, public IDrawable, public IUpdatable
{
private:
	sf::Sprite sprite;
	void UpdateDrawPos();
	float rotation = 0;
public:
	SpriteRenderer(GameObject * gamobject = nullptr, std::string spriteName = "Error", sf::IntRect spriteRect = sf::IntRect(0, 0, 64, 64), float rotation = 0);
	~SpriteRenderer();

	float GetRotation();
	void SetRotation(float rotationChange);
	sf::IntRect spriteRect;

	// Inherited via IDrawable
	virtual void Draw(sf::RenderWindow * window) override;

	//Implement acess to textures
	TextureManager& texmgr = TextureManager::getInstance();

	// Inherited via IUpdatable
	virtual void Update(sf::Time deltaTime) override;
};

#endif