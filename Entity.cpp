#include "pch.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity()
{
}

Entity::Entity(sf::Vector2f position)
{
}

Entity::Entity(sf::Vector2f position, string texturePath)
{
	mSprite.setPosition(position);
	mSprite.setTexture(mTexture);
	mTexture.loadFromFile(texturePath);
}


void Entity::GoRight(sf::Time elapsedTime)
{
	if (!CollidesBlock())
	{
		GoesToTheRight = true;
		sf::Vector2f movement(0.f, 0.f);
		movement.x += m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
	}
}

void Entity::GoLeft(sf::Time elapsedTime)
{
	if (!CollidesBlock())
	{
		GoesToTheRight = false;
		sf::Vector2f movement(0.f, 0.f);
		movement.x -= m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
	}
}

bool Entity::ClimbLadder(sf::Time elapsedTime)
{
	if (this->IsOnLadder())
	{
		sf::Vector2f movement(0.f, 0.f);
		movement.y -= m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
		return true;
	}
	return false;
}

bool Entity::GoDown(sf::Time elapsedTime)
{
	if (this->OnALadder())
	{
		sf::Vector2f movement(0.f, 0.f);
		movement.y += m_speed;
		this->mSprite.move(movement * elapsedTime.asSeconds());
		return true;
	}
	return false;
}

bool Entity::IsOnLadder()
{
	for (shared_ptr<Entity> ladder : EntityManager::mLadders)
	{
		sf::FloatRect ladderBounds = ladder->mSprite.getGlobalBounds();
		ladderBounds.top -= 33;
		ladderBounds.height += 33;
		ladderBounds.left += 13;
		ladderBounds.width -= 20;

		sf::FloatRect entityBounds = this->mSprite.getGlobalBounds();
		if (entityBounds.intersects(ladderBounds))
		{
			return true;
		}
	}
	return false;
}

bool Entity::OnALadder()
{
	for (shared_ptr<Entity> entity : EntityManager::mLadders)
	{
		sf::FloatRect ladderBounds = entity->mSprite.getGlobalBounds();
		sf::FloatRect entityBounds = this->mSprite.getGlobalBounds();
		ladderBounds.top -= this->mSprite.getTexture()->getSize().y + 10;
		ladderBounds.height += 13;

		if (entityBounds.intersects(ladderBounds))
		{
			return true;
		}
	}
	return false;
}

bool Entity::CollidesBlock() {
	for (shared_ptr<Entity> block : EntityManager::mBlocks)
	{
		sf::FloatRect entityBounds = this->mSprite.getGlobalBounds();
		sf::FloatRect blockBounds = block->mSprite.getGlobalBounds();
		if (entityBounds.intersects(blockBounds))
		{
			return true;
		}
	}
	return false;
}

void Entity::UpdateTexture(string path)
{
	Textures textures;
	mTexture.loadFromFile(path);
	mSprite.setTexture(mTexture);
}
