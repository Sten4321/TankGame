#include "Transform.h"



Transform::Transform(sf::Vector2f position, GameObject * gameobject) : Component(gameobject)
{
	this->position = position;
}


Transform::~Transform()
{
}

//Move an object
void Transform::Translate(sf::Vector2f translation)
{
	if (canMove)
	{
		if (position.y <= 0 && translation.y <= 0)
		{
			translation.y = 0;
		}
		if (position.x <= 0 && translation.x <= 0)
		{
			translation.x = 0;
		}
		if (position.y >= 720 && translation.y >= 0)
		{
			translation.y = 0;
		}
		if (position.x >= 1280 && translation.x >= 0)
		{
			translation.x = 0;
		}
		position += translation;
	}
}
