#include "GameObject.h"
using namespace sf;

GameObject::GameObject()
	: Component(*this)
{
}


GameObject::~GameObject()
{
}

void GameObject::Add(Component * addComponent)
{
	components->push_back(addComponent);
}

void GameObject::Update()
{
	vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<IUpdatable*>((*it)))
		{

		}
	}
}

void GameObject::Draw(RenderWindow * window)
{
}
