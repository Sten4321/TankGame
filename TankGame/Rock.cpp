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
