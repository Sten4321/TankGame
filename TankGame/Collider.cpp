#include "Collider.h"
#include "GameWorld.h"


Collider::Collider(GameObject * gameobject) : Component(gameobject)
{
	GameWorld::colliders->push_back(this);
}


Collider::~Collider()
{
	std::vector<Collider*>::iterator it;
	for (it = GameWorld::colliders->begin(); it != GameWorld::colliders->end(); it++)
	{
		if (*it == this)
		{
			GameWorld::colliders->erase(it);
			break;
		}
	}
}

sf::CircleShape Collider::CollisionBox()
{
	sf::CircleShape collisionbox;

	collisionbox.setRadius((float)(GetComponent(SpriteRenderer)->spriteRect.width / 2));

	collisionbox.setPosition(GetComponent(Transform)->position.x, GetComponent(Transform)->position.y);
	return collisionbox;
}

//cleans up colliders
void Collider::RemoveCollider()
{
	if (removeOtherColliders.size() > 0)
	{
		std::vector<Collider*>::iterator it;
		for (auto it = otherColliders.begin(); it != otherColliders.end(); )
		{
			if (std::find(removeOtherColliders.begin(), removeOtherColliders.end(), *it) != removeOtherColliders.end())
			{
				it = otherColliders.erase(it);
			}
			else
			{
				++it;
			}
		}
		removeOtherColliders.clear();
	}
}

//checks if circle is in another circle
bool Collider::Intersects(sf::CircleShape other)
{
	float distanceBetweenCenters = (other.getPosition().x - CollisionBox().getPosition().x)*(other.getPosition().x - CollisionBox().getPosition().x) + (other.getPosition().y - CollisionBox().getPosition().y)*(other.getPosition().y - CollisionBox().getPosition().y);
	if (distanceBetweenCenters <= pow(CollisionBox().getRadius() + other.getRadius(), 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//checks collisions
void Collider::CheckCollision()
{
	if (doCollisionChecks)
	{
		std::vector<Collider*>::iterator it;
		for (it = GameWorld::colliders->begin(); it != GameWorld::colliders->end(); it++)
		{
			if (*it != this)
			{
				if (Intersects((*it)->CollisionBox()))
				{
					if (!(std::find(otherColliders.begin(), otherColliders.end(), *it) != otherColliders.end()))
					{
						gameObject->OnCollisionEnter(**it);
						otherColliders.push_back(*it);
					}
				}
			}
		}
	}
	if (otherColliders.size() > 0)
	{
		std::vector<Collider*>::iterator it;
		for (it = otherColliders.begin(); it != otherColliders.end(); it++)
		{
			if (*it != this)
			{
				if (Intersects((*it)->CollisionBox()))
				{
					gameObject->OnCollisionStay(**it);
				}
				else
				{
					gameObject->OnCollisionExit(**it);
					removeOtherColliders.push_back(*it);
				}
			}
		}
	}
	if (removeOtherColliders.size() > 0)
	{
		RemoveCollider();
	}
}

//updates the collider
void Collider::Update(sf::Time deltaTime)
{
	CheckCollision();
}
