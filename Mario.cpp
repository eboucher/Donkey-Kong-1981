#include "pch.h"
#include "Mario.h"

Mario::Mario(const sf::Texture& texture, sf::Vector2f position)
	: MarioSpeed(DEFAULT_SPEED), isMovingRight(false), isMovingLeft(false),
	  isMovingUp(false), isMovingDown(false),
	  isOnLadder(false), isJumping(false),
	  Entity(EntityType::mario, texture, position)
{
}


Mario::~Mario()
{
}


void Mario::setFalling(bool value)
{
	isFalling = value;
}



void Mario::HandleInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up) {
		if (!isMovingDown) {
			isMovingUp = isPressed;
		}
	}
	if (key == sf::Keyboard::Left) {
		isMovingLeft = isPressed;
	}
	if (key == sf::Keyboard::Right) {
		isMovingRight = isPressed;
	}
	else if (key == sf::Keyboard::Space) {
		if (isPressed == false)
		{
			return;
		}
	}
}

void Mario::UpdateMario(sf::Time elapsedTime)
{
	
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingRight)
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