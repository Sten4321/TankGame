#include "SpriteRenderer.h"
#include "Transform.h"

void SpriteRenderer::UpdateDrawPos()
{
	sprite.setPosition(((dynamic_cast<Transform*>((*Component::gameObject).getComponent("Transform")))->position));
}

void SpriteRenderer::Update()
{
	UpdateDrawPos();
	sprite.setRotation(rotation);
}

//Draws Sprites out to screen
void SpriteRenderer::Draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}


SpriteRenderer::SpriteRenderer(GameObject * gameobject, std::string spriteName, float rotation) : Component(gameobject)
{
	this->rotation = rotation;
	sprite.setTexture(texmgr.getRef(spriteName));
	Update();//Update on creation
}


SpriteRenderer::~SpriteRenderer()
{
}