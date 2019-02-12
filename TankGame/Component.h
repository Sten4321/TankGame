#pragma once
#ifndef COMPONENT
#define COMPONENT

class GameObject;

class Component
{
public:
	Component(GameObject * gameObject);
	virtual ~Component();
	GameObject * gameObject;
};
#endif

