#include "Animation.h"

Animation::Animation(unsigned int startFrame, unsigned int endFrame, float duration)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->duration = duration;
}

Animation::~Animation()
{
}