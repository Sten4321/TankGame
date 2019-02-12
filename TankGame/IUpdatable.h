#pragma once
#ifndef UPDATABLE
#define UPDATABLE

class IUpdatable
{
public:
	IUpdatable();
	virtual ~IUpdatable();
	virtual void Update()=0;
};

#endif