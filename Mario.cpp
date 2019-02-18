#include "pch.h"
#include "Mario.h"

Mario::Mario(const sf::Texture& texture, sf::Vector2f position)
{
}


Mario::~Mario()
{
}


void Mario::UpdateMario(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (Mario::isMovingRight)
		movement.y -= MarioSpeed;
	if (isMovingDown)
		movement.y += MarioSpeed;
	if (isMovingLeft)
		movement.x -= MarioSpeed;
	if (isMovingRight)
		movement.x += MarioSpeed;

	Entity::m_sprite.move(movement * elapsedTime.asSeconds());
}


bool Mario::StandsOnGround()
{
	return false;
}