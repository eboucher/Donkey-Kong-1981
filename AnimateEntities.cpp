#include "pch.h"
#include "AnimateEntities.h"
#include "EntityManager.h"


AnimateEntity::AnimateEntity(EntityType type, const sf::Texture& texture, sf::Vector2f position) :
	mIsMovingLeft(false), mIsMovingRight(false),
	mIsMovingDown(false),
	Entity(type, texture, position)
{
}