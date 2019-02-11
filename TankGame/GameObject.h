#pragma once
#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Component.h"
#include "IUpdatable.h"
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class GameObject : public Component
{
public:
	vector<Component*> * components = new vector<Component*>;
	/*Vector since i need a container of unspecified size,
	that may or may not grow (or shrink)*/
	GameObject();
	virtual ~GameObject();
	void Add(Component* component);//add Component
	void Update();
	void Draw(RenderWindow * window);

};
#endif

