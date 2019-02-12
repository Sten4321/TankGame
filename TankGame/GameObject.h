#pragma once
#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"
#include "Transform.h"
#include "SFML/Graphics.hpp"

class GameObject : public Component
{
public:
	std::vector<Component*> * components = new std::vector<Component*>;
	/*Vector since i need a container of unspecified size,
	that may or may not grow (or shrink)*/
	GameObject(sf::Vector2f position = sf::Vector2f(0, 0));
	virtual ~GameObject();
	void Add(Component* component);//add Component
	void Update();
	void Draw(sf::RenderWindow * window);

};
#endif

