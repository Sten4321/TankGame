#pragma once
#ifndef ANIMATION
#define ANIMATION

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:

	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration);
	~Animation();

	unsigned int getLength() { return endFrame - startFrame + 1; }
};

#endif