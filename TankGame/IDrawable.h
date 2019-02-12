#pragma once
#ifndef IDRAWABLE
#define IDRAWABLE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
class IDrawable
{
public:
	IDrawable();
	virtual ~IDrawable();
	virtual void Draw(sf::RenderWindow * window)=0;
};

#endif