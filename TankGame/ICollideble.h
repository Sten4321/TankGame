#pragma once
#ifndef ICOLLIDEBLE
#define ICOLLIDEBLE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Collider.h"

class ICollideble
{
public:
	ICollideble();
	virtual ~ICollideble();
	virtual void CollisionEnter(Collider other) = 0;
	virtual void CollisionExit(Collider other) = 0;
	virtual void CollisionStay(Collider other) = 0;
};

#endif