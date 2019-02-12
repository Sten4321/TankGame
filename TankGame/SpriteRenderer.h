#pragma once
#ifndef SPRITERENDERER
#define SPRITERENDERER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "IDrawable.h"

class GameObject;

class SpriteRenderer:public Component, public IDrawable
{
public:
	SpriteRenderer(GameObject * gamobject = nullptr);
	~SpriteRenderer();

	// Inherited via IDrawable
	virtual void Draw(sf::RenderWindow * window) override;
};

#endif