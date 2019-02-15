#pragma once
#ifndef ANIMATIONHANDLER
#define ANIMATIONHANDLER
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "Animation.h"
class AnimationHandler
{
private:

	//Array of animations
	std::vector<Animation> animations;

	//Current time since the animation loop started
	float t;

	int currentAnim;

public:

	// Add a new animation
	void addAnim(Animation& anim);

	/* Update the current frame of animation. dt is the time since
	 * the update was last called (i.e. the time for one frame to be
	 * executed) */
	void update(sf::Time dt);

	// Change the animation, resetting t in the process
	void changeAnim(unsigned int animNum);

	// Rect of the texture that should be displayed
	sf::IntRect bounds;

	//Pixel dimensions of each individual frame
	sf::IntRect frameSize;

	//Constructor
	AnimationHandler();
	AnimationHandler(const sf::IntRect& frameSize);
	~AnimationHandler();
};

#endif