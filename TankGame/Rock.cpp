#include "Rock.h"
#include "SpriteRenderer.h"

Rock::Rock(GameObject * gameobject) : Component(gameobject)
{
	GetComponent(Transform)->canMove = false;
	Animation staticAn = Animation(0, 0, 1.0f);
	GetComponent(SpriteRenderer)->AnimationHnd.addAnim(staticAn);
	GetComponent(SpriteRenderer)->AnimationHnd.changeAnim(0);
}


Rock::~Rock()
{
}

void Rock::CollisionEnter(Collider other)
{
	std::cout << "Rock Enter\n";
}

void Rock::CollisionExit(Collider other)
{
	std::cout << "Rock Exit\n";
}

//push back all objects inside the rock
void Rock::CollisionStay(Collider other)
{
	float force = 4;

	sf::Vector2f dir = (dynamic_cast<Transform*>((*other.gameObject).getComponent("Transform")))->position - GetComponent(Transform)->position;
	float dirMagnitude = sqrt(dir.x*dir.x + dir.y*dir.y);
	dir.x = dir.x / dirMagnitude;
	dir.y = dir.y / dirMagnitude;
	(dynamic_cast<Transform*>((*other.gameObject).getComponent("Transform")))->Translate(dir * force);
}
