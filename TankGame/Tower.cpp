#include "Tower.h"
#include "SpriteRenderer.h"
#include "GameWorld.h"

void Tower::SetHealth(int healthChange)
{
	health += healthChange;
	if (health < 0)
	{
		health = 0;
		Die();
	}
}

// Calculates the degrees from standart vector(up) to destination vector(towards target).
float Tower::GetDegreesFromDestination(sf::Vector2f destinationVec)
{
	sf::Vector2f positionVec = sf::Vector2f(0, -1); //Standard position (UP)

	float toppart = 0;
	toppart += positionVec.x * destinationVec.x;
	toppart += positionVec.y * destinationVec.y;

	float destinationVector2 = 0; //destinationVec squared
	float positionVector2 = 0; //positionVec squared

	destinationVector2 += positionVec.x * positionVec.x;
	destinationVector2 += positionVec.y * positionVec.y;

	positionVector2 += destinationVec.x * destinationVec.x;
	positionVector2 += destinationVec.y * destinationVec.y;


	float bottompart = 0;
	bottompart = (float)sqrt(destinationVector2 * positionVector2);


	double returnValue = (float)acos(toppart / bottompart);

	returnValue *= 360.0 / (2 * PI); //Coverts the radian to degrees

	if (returnValue < 0)
	{
		returnValue -= (returnValue * 2);
	}

	return (float)returnValue;
}

bool Tower::Intersects(sf::Vector2f other, float radius)
{
	float distanceBetweenCenters = (other.x - AttackRadius().getPosition().x)*(other.x - AttackRadius().getPosition().x) + (other.y - AttackRadius().getPosition().y)*(other.y - AttackRadius().getPosition().y);
	if (distanceBetweenCenters <= pow(AttackRadius().getRadius() + radius, 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

sf::CircleShape Tower::AttackRadius()
{
	sf::CircleShape attackRadius;

	attackRadius.setRadius(attackRange);

	attackRadius.setPosition(GetComponent(Transform)->position.x, GetComponent(Transform)->position.y);
	return attackRadius;
}

Collider * Tower::FindEnemiesInRange()
{
	Collider* player = nullptr;
	std::vector<Collider*>::iterator it;
	for (it = GameWorld::colliders->begin(); it != GameWorld::colliders->end(); it++)
	{
		Component* type = dynamic_cast<Player*>((*it)->gameObject->getComponent("Player"));
		if (dynamic_cast<Player*>(type))
		{
			if (Intersects((*it)->CollisionBox().getPosition(), (*it)->CollisionBox().getRadius()))
			{
				player = (*it);
			}
		}
		return player;
	}
}

void Tower::Shoot()
{
	if (shootTimeStamp + attackRate <= timePassed)
	{
		Collider* target = nullptr;
		target = FindEnemiesInRange();
		if (target != nullptr)
		{
			sf::Vector2f direction = (dynamic_cast<Transform*>((*target->gameObject).getComponent("Transform")))->position - GetComponent(Transform)->position;
			float dirMagnitude = sqrt(direction.x*direction.x + direction.y*direction.y);
			direction.x = direction.x / dirMagnitude;
			direction.y = direction.y / dirMagnitude;

			float rotation = GetDegreesFromDestination(direction);
			GameWorld::gen.GenerateBulletSmall(GetComponent(Transform)->position, rotation);
			shootTimeStamp = timePassed;
		}
	}
}

void Tower::AddAnimations()
{
	Animation staticAn = Animation(0, 0, 1.0f);
	Animation idleAn = Animation(0, 4, 0.2f);
	GetComponent(SpriteRenderer)->AnimationHnd.addAnim(staticAn);
	GetComponent(SpriteRenderer)->AnimationHnd.addAnim(idleAn);
	GetComponent(SpriteRenderer)->AnimationHnd.changeAnim(1);
}

void Tower::Die()
{
	GameWorld::AddRemoveGameObject(this->gameObject);
}

Tower::Tower(GameObject * gameObject, int health, float attackRate, float attackRange, int spread) : Component(gameObject)
{
	this->health = health;
	this->attackRate = attackRate;
	this->attackRange = attackRange;
	this->spread = spread;
	AddAnimations();
}

Tower::~Tower()
{
}

void Tower::Update(sf::Time deltaTime)
{
	Shoot();
	timePassed += deltaTime.asSeconds();
}

void Tower::CollisionEnter(Collider other)
{
}

void Tower::CollisionExit(Collider other)
{
}

void Tower::CollisionStay(Collider other)
{
	float force = 4;

	sf::Vector2f dir = (dynamic_cast<Transform*>((*other.gameObject).getComponent("Transform")))->position - GetComponent(Transform)->position;
	float dirMagnitude = sqrt(dir.x*dir.x + dir.y*dir.y);
	dir.x = dir.x / dirMagnitude;
	dir.y = dir.y / dirMagnitude;
	(dynamic_cast<Transform*>((*other.gameObject).getComponent("Transform")))->Translate(dir * force);
}
