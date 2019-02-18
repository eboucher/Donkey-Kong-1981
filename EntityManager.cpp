#include "pch.h"
#include "EntityManager.h"
using namespace std;

shared_ptr<Mario> EntityManager::mMario;
vector<shared_ptr<Ground>> EntityManager::mGroundBlocks;
vector<shared_ptr<Ladder>> EntityManager::mLadders;

EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::SetMario(sf::Vector2f position)
{
	sf::Texture texture;
	texture.loadFromFile("Media/Textures/Mario.png");
	position.x = 0.f;
	position.y = 0.f;
	shared_ptr<Mario> ptr = make_shared<Mario>(texture, position);
	EntityManager::mMario = ptr;
}


shared_ptr<Mario> EntityManager::GetMario() {
	return EntityManager::mMario;
}


void EntityManager::AddGroundBlock(sf::Vector2f position)
{
	sf::Texture texture;
	texture.loadFromFile("Media/Textures/Block.png");
	shared_ptr<Ground> groundPtr = make_shared<Ground>(texture, position);
	EntityManager::mGroundBlocks.push_back(groundPtr);
}


vector<shared_ptr<Ground>> EntityManager::GetGroundBlocks()
{
	return EntityManager::mGroundBlocks;
}


void EntityManager::AddLadder(sf::Vector2f position)
{
	sf::Texture texture;
	texture.loadFromFile("Media/Textures/ladder.png");
	shared_ptr<Ladder> ptr = make_shared<Ladder>(texture, position);
	EntityManager::mLadders.push_back(ptr);
}


vector<shared_ptr<Entity>> EntityManager::GetLadders()
{
	vector<shared_ptr<Entity>> ladders;
	return ladders;
}

void EntityManager::UpdateEntities(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	for (shared_ptr<Entity> mario : EntityManager::m_Entities)
	{
		if (entity->m_enabled == false)
		{
			continue;
		}

		if (entity->m_type != EntityType::mario)
		{
			continue;
		}

		mario->m_sprite.move(movement * elapsedTime.asSeconds());
	}
}
