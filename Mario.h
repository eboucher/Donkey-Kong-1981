#pragma once
#include "pch.h"
#include "Entity.h"
#include "Textures.h"

#define JUMPING_FRAMES 10
#define FLYING_FRAMES 15

using namespace std;

class Mario : public Entity
{
public:
	Mario(sf::Vector2f position);
	virtual ~Mario();
	

public:
	bool TouchBowser();
	bool GoDown(sf::Time elapsedTime);
	void GoLeft(sf::Time elapsedTime); 
	void GoRight(sf::Time elapsedTime); 
	bool ClimbLadder(sf::Time elapsedTime);
	void Jump(sf::Time elapsedTime);
	void GravityHandle();

public:
	bool mIsJumping = false;
	int jumpingCaption = 0;
	int fallingCaption = 10;
	int flyingCaption = 0;
};

