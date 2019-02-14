#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

Player::Player(GameObject * gameobject) : Component(gameobject)
{
	rotation = GetComponent(SpriteRenderer)->GetRotation();
}


Player::~Player()
{
}

int Player::GetHealth()
{
	return health;
}

void Player::SetHealth(int healthChange)
{
	health += healthChange;
	if (health < 0)
	{
		health = 0;
	}
	if (health > 100)
	{
		health = 100;
	}
}

//handles player death
void Player::Die()
{
	//TODO: Implement Die
}

//Handles movement for the player
sf::Vector2f Player::Movement(sf::Vector2f translation)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		translation += sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		translation += sf::Vector2f(0, 1);
	}
	return translation;
}

//Handles rotation of the player
void Player::Rotate()
{
	sf::Vector2f translation = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotation -= rotateSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotation += rotateSpeed;
	}
	if (rotation > 360)
	{
		rotation = 0;
	}
	if (rotation < 0)
	{
		rotation = 360;
	}
}

//rotates the vector according to its degree rotation
sf::Vector2f Player::RotateVector(sf::Vector2f vector)
{
	float rotationInRad = (float)((rotation * PI) / 180);
	//vector.x = vector.x * cos(rotationInRad);
	//vector.y = vector.y * -sin(rotationInRad);

	float cs = cos(rotationInRad);
	float sn = sin(rotationInRad);

	float px = vector.x * cs - vector.y * sn;
	float py = vector.x * sn + vector.y * cs;

	sf::Vector2f translation = sf::Vector2f(px, py);

	return translation;
}

//Updates the gameobjects position
void Player::TranslateMovement(sf::Vector2f Translation, sf::Time deltaTime)
{
	sf::Vector2f movementdirection = Translation;
	movementdirection.x = movementdirection.x * deltaTime.asSeconds() * movespeed;
	movementdirection.y = movementdirection.y * deltaTime.asSeconds() * movespeed;
	GetComponent(SpriteRenderer)->SetRotation(rotation);
	GetComponent(Transform)->Translate(movementdirection);
}

//Updates the player object
void Player::Update(sf::Time deltaTime)
{
	sf::Vector2f translation = sf::Vector2f(0, 0);
	Rotate();
	translation = Movement(translation);
	translation = RotateVector(translation);
	TranslateMovement(translation, deltaTime);
}
