#pragma once
#ifndef ROCK
#define ROCK
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Window.hpp"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "GameWorld.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))


class Rock :public Component
{
public:
	Rock(GameObject * gameobject = nullptr);
	~Rock();
};

#endif