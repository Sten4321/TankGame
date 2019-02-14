#include "SpriteRenderer.h"
#include "Transform.h"

void SpriteRenderer::UpdateDrawPos()
{
	sprite.setPosition(GetComponent(Transform)->position);
}

void SpriteRenderer::Update(sf::Time deltaTime)
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
	sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
	Update(sf::seconds(0.1f));//Update on creation
}


SpriteRenderer::~SpriteRenderer()
{
}

float SpriteRenderer::GetRotation()
{
	return rotation;
}

void SpriteRenderer::SetRotation(float rotationChange)
{
	rotation = rotationChange;
	if (rotation > 360)
	{
		rotation = 0;
	}
	if (rotation < 0)
	{
		rotation = 360;
	}
}
