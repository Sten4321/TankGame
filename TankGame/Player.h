#pragma once
#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Window.hpp"
#include "Component.h"
#include "IUpdatable.h"

class Player:public Component, public IUpdatable
{
public:
	Player(GameObject * gameobject = nullptr);
	~Player();

	// Inherited via IUpdatable
	virtual void Update() override;
};

#endif