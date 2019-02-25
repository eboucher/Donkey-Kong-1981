#include "pch.h"
#include "Mario.h"
#include "EntityManager.h"

Mario::Mario(sf::Vector2f position) : Entity(position)
{
	m_speed = 150.f;

	UpdateTexture("Media/Textures/mario_right.png");
	mSprite.setPosition(position);
}

Mario::~Mario()
{
}


void Mario::Jump(sf::Time elapsedTime) {
	Textures textures;
	if (!this->IsOnLadder()) {
		if (GoesToTheRight)
			UpdateTexture(textures.RightJumpTexturePath);
		else
			UpdateTexture(textures.LeftJumpTexturePath);

		sf::Vector2f movement(0.f, 0.f);
		movement.y -= m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
	}
}

void Mario::GravityHandle() {
	Textures textures;
	if (fallingCaption != JUMPING_FRAMES) {
		if (GoesToTheRight)
			UpdateTexture(textures.RightJumpTexturePath);
		else
			UpdateTexture(textures.LeftJumpTexturePath);
	}
	if (flyingCaption > 0 && flyingCaption < FLYING_FRAMES) {
		flyingCaption++;
	}
	else {
		if (jumpingCaption == JUMPING_FRAMES) {
			flyingCaption++;
			mIsJumping = false;
		}
		if (!mIsJumping)
			jumpingCaption = 0;
		if (!mIsJumping && fallingCaption != JUMPING_FRAMES)
			fallingCaption++;
		if (mIsJumping) {
			jumpingCaption++;
			fallingCaption--;
		}
		if (flyingCaption == FLYING_FRAMES)
			flyingCaption = 0;
	}
}

bool Mario::TouchBowser()
{

	sf::FloatRect fr = EntityManager::mPeach->mSprite.getGlobalBounds();
	if (this->mSprite.getGlobalBounds().intersects(fr))
	{
		return true;
	}
	return false;
}


void Mario::GoLeft(sf::Time elapsedTime)
{
	Textures textures;
	if (fallingCaption == JUMPING_FRAMES) {
		UpdateTexture(textures.leftTexturePath);
	}
	Entity::GoLeft(elapsedTime);
}

void Mario::GoRight(sf::Time elapsedTime)
{
	Textures textures;
	if (fallingCaption == JUMPING_FRAMES) {
		UpdateTexture(textures.RightTexturePath);
	}
	Entity::GoRight(elapsedTime);
}

bool Mario::ClimbLadder(sf::Time elapsedTime)
{
	Textures textures;
	if(OnALadder())
		UpdateTexture(textures.UpTexturePath);
	return Entity::ClimbLadder(elapsedTime); 
}

bool Mario::GoDown(sf::Time elapsedTime)
{
	Textures textures;
	if (this->OnALadder())
	{
		if (IsOnLadder())
			UpdateTexture(textures.UpTexturePath);

		sf::Vector2f movement(0.f, 0.f);
		movement.y += m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
		return true;
	}
	return false;
}



