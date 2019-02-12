#include "Transform.h"



Transform::Transform(sf::Vector2f position, GameObject * gameobject) : Component(gameobject)
{
	this->position = position;
}


Transform::~Transform()
{
}

void Transform::Translate(sf::Vector2f translation)
{
	if (canMove)
	{
		position += translation;
	}
}
