#include "GameObject.h"

//Adds an component to the list of components
void GameObject::Add(Component * addComponent)
{
	if (components)
	{
		components->push_back(addComponent);
	}
}

//Calls the update method in the components that can be updated
void GameObject::Update()
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)
	{
		if (dynamic_cast<IUpdatable*>((*it)))
		{
			dynamic_cast<IUpdatable*>((*it))->Update();
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

//Constructer for GameObject
GameObject::GameObject(sf::Vector2f position)
	: Component(this)
{
	Add(new Transform(position, this));//adds a position to the object
}


GameObject::~GameObject()
{
	std::vector<Component*>::iterator it;
	for (it = components->begin(); it != components->end(); it++)/*call deconstructer on all components,
																 to make sure it is deleted and no causing memory leaks*/
	{
		delete (*it);
	}
	components->clear();
	delete components;//don't know if these 2 lines are necerssary
	components = nullptr;
}