#include "GameObject.h"

//Adds an component to the list of components
void GameObject::AddComponent(Component * addComponent)
{
	if (components)
	{
		components->push_back(addComponent);
	}
}

//Calls the update method in the components that can be updated
void GameObject::Update(sf::Time deltaTime)
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<IUpdatable*>((*it)))
		{
			dynamic_cast<IUpdatable*>((*it))->Update(deltaTime);
		}
	}
}

//Calls the Draw method in the components that can be drawed
void GameObject::Draw(sf::RenderWindow * window)
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<IDrawable*>((*it)))
		{
			dynamic_cast<IDrawable*>((*it))->Draw(window);
		}
	}
}

//Calls the Draw method in the components that can be drawed
void GameObject::OnCollisionEnter(Collider other)
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<ICollideble*>((*it)))
		{
			dynamic_cast<ICollideble*>((*it))->CollisionEnter(other);
		}
	}
}

//Calls the Draw method in the components that can be drawed
void GameObject::OnCollisionExit(Collider other)
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<ICollideble*>((*it)))
		{
			dynamic_cast<ICollideble*>((*it))->CollisionExit(other);
		}
	}
}

//Calls the Draw method in the components that can be drawed
void GameObject::OnCollisionStay(Collider other)
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<ICollideble*>((*it)))
		{
			dynamic_cast<ICollideble*>((*it))->CollisionStay(other);
		}
	}
}

//Returns a component if it exist
Component* GameObject::getComponent(std::string componentName)
{
	std::string comparestring = "class " + componentName;
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (typeid(**it).name() == comparestring)
		{
			return (*it);
		}
	}
	return nullptr;
}

//Constructer for GameObject
GameObject::GameObject(sf::Vector2f position)
	: Component(this)
{
	AddComponent(new Transform(position, this));//adds a position to the object
}


GameObject::~GameObject()
{
	if (components)
	{
		std::vector<Component*>::iterator it;
		for (it = components->begin(); it != components->end(); it++)
		{
			delete (*it);
		}
		components->clear();
	}
}