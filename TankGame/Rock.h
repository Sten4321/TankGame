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
#include "ICollideble.h"
#include "Transform.h"
#define GetComponent(x) (dynamic_cast<x*>((*Component::gameObject).getComponent(#x)))


class Rock :public Component,public ICollideble
{
public:
	Rock(GameObject * gameobject = nullptr);
	~Rock();

	// Inherited via ICollideble
	virtual void CollisionEnter(Collider other) override;
	virtual void CollisionExit(Collider other) override;
	virtual void CollisionStay(Collider other) override;
};

#endif