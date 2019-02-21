#include "Bullet.h"
#include "GameWorld.h"

#include "SpriteRenderer.h"
#include "Player.h"
#include "Rock.h"

//Destroys the bullet
void Bullet::DestroyBullet()
{
	GameWorld::AddRemoveGameObject(this->gameObject);
}

sf::Vector2f Bullet::MoveForward(sf::Vector2f translation)
{
	translation += sf::Vector2f(0, -1);

	return translation;
}

sf::Vector2f Bullet::RotateVector(sf::Vector2f translation)
{
	float rotationInRad = (float)((rotation * PI) / 180);
	//vector.x = vector.x * cos(rotationInRad);
	//vector.y = vector.y * -sin(rotationInRad);

	float cs = cos(rotationInRad);
	float sn = sin(rotationInRad);

	float px = translation.x * cs - translation.y * sn;
	float py = translation.x * sn + translation.y * cs;

	translation = sf::Vector2f(px, py);

	return translation;
}

float Bullet::GetDegreesFromDestination(sf::Vector2f translation)
{
	std::cout << "degree cal\n";
	sf::Vector2f positionVec = sf::Vector2f(0, -1); //Standard position (UP)

	float toppart = 0;
	toppart += positionVec.x * translation.x;
	toppart += positionVec.y * translation.y;

	float destinationVector2 = 0; //destinationVec squared
	float positionVector2 = 0; //positionVec squared

	destinationVector2 += positionVec.x * translation.x;
	destinationVector2 += positionVec.y * translation.y;

	positionVector2 += translation.x * translation.x;
	positionVector2 += translation.y * translation.y;

	float bottompart = 0;
	bottompart = (float)sqrt(destinationVector2 * positionVector2);

	double returnValue = (float)acos(toppart / bottompart);

	returnValue *= 360.0 / (2 * PI); //Coverts the radian to degrees

	if (translation.x < 0)
	{
		returnValue -= (returnValue * 2);
	}
	return (float)returnValue;
}

void Bullet::TranslateMovement(sf::Vector2f translation, sf::Time deltaTime)
{
	sf::Vector2f movementdirection = translation;
	movementdirection.x = movementdirection.x * deltaTime.asSeconds() * movementSpeed;
	movementdirection.y = movementdirection.y * deltaTime.asSeconds() * movementSpeed;
	GetComponent(Transform)->Translate(movementdirection);
}

void Bullet::AddAnimations()
{
	Animation staticAn = Animation(0, 0, 1.0f);
	GetComponent(SpriteRenderer)->AnimationHnd.addAnim(staticAn);
	GetComponent(SpriteRenderer)->AnimationHnd.changeAnim(0);
}

Bullet::Bullet(GameObject * gameObject, int bulletDmg, float movementSpeed, float rotation, float lifeSpan) :Component(gameObject)
{
	this->bulletDmg = bulletDmg;
	this->movementSpeed = movementSpeed;
	this->lifeSpan = lifeSpan;
	this->rotation = rotation;
	GetComponent(SpriteRenderer)->SetRotation(rotation);
	AddAnimations();
}

Bullet::~Bullet()
{
}

//Handles movement of the bullet
void Bullet::BulletMovement(sf::Time deltaTime)
{
	sf::Vector2f translation = sf::Vector2f();
	//Bullet travels forward
	translation = MoveForward(translation);

	//"forward" is changed to fit the angle
	translation = RotateVector(translation);

	//Translates movemement
	TranslateMovement(translation, deltaTime);
}

//Removes bullet if time runs out
void Bullet::CheckIfBulletIsExpired(sf::Time deltaTime)
{
	if (timePassed >= lifeSpan)
	{
		shouldDie = true;

		DestroyBullet();
	}
}

//Update bullet
void Bullet::Update(sf::Time deltaTime)
{
	BulletMovement(deltaTime);
	CheckIfBulletIsExpired(deltaTime);
	timePassed += deltaTime.asSeconds();
}

void Bullet::CollisionEnter(Collider other)
{
	if (timePassed >= 0.04f)//anti crash measure :(
	{
		bool done = false;
		Component* type = dynamic_cast<Rock*>(other.gameObject->getComponent("Rock"));
		if (type != nullptr && !done)
		{
			if (dynamic_cast<Rock*>(type))
			{
				shouldDie = true;
				done = true;
			}
		}
		type = dynamic_cast<Player*>(other.gameObject->getComponent("Player"));
		if (type != nullptr && !done)
		{
			if (dynamic_cast<Player*>(type))
			{
				((Player*)type)->SetHealth(-bulletDmg);//Crashes the game if done too fast?..
				shouldDie = true;
				done = true;
			}
		}
		type = dynamic_cast<Tower*>(other.gameObject->getComponent("Tower"));
		if (type != nullptr && !done)
		{
			if (dynamic_cast<Tower*>(type))
			{
				((Tower*)type)->SetHealth(-bulletDmg);//Crashes the game if done too fast?..
				shouldDie = true;
				done = true;
			}
		}
		if (shouldDie)
		{
			DestroyBullet();
		}
	}
}

void Bullet::CollisionExit(Collider other)
{

}

void Bullet::CollisionStay(Collider other)
{

}
