#pragma once
#ifndef UPDATABLE
#define UPDATABLE
#include "SFML/Graphics.hpp"

class IUpdatable
{
public:
	IUpdatable();
	virtual ~IUpdatable();
	virtual void Update(sf::Time deltaTime)=0;
};

#endif