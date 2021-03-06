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
#include "ICollideble.h"
#include "Collider.h"
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
	void AddComponent(Component* component);//add Component
	void Update(sf::Time deltaTime);
	void Draw(sf::RenderWindow * window);
	Component* getComponent(std::string componentName);
	void OnCollisionEnter(Collider other);
	void OnCollisionExit(Collider other);
	void OnCollisionStay(Collider other);
};
#endif

