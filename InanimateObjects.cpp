#include "pch.h"
#include "InanimateObjects.h"


Ground::Ground(const sf::Texture& texture, sf::Vector2f position)
	: Entity(EntityType::ground, texture, position)
{
}


Ground::~Ground()
{
}


Ladder::Ladder(const sf::Texture& texture, sf::Vector2f position)
	: Entity(EntityType::ladder, texture, position)
{
}


Ladder::~Ladder()
{
}