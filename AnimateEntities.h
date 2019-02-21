#pragma once
#include "Entity.h"

class AnimateEntity :
	public Entity
{
  public:
	AnimateEntity(EntityType type,
				  const sf::Texture& texture, 
		          sf::Vector2f position);
	virtual ~AnimateEntity() { };

protected:
	bool mStateRight; // true => right, false => left
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;

	int mAnimationState;

	virtual void hitGround() = 0;

	virtual void move(sf::Vector2f movement) = 0;

public:
	virtual void updateAnimation(const sf::Time elapsedTime) = 0;

};