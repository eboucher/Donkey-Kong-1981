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

void EntityManager::addNewEntity(const EntityType entityType, sf::Vector2f position)
{
	sf::Texture texture;

	if (entityType == EntityType::mario) {
		texture.loadFromFile("Media/Textures/Mario.png");
		position.x = 0.f;
		position.y = 0.f;
		shared_ptr<Mario> ptr = make_shared<Mario>(texture, position);
		EntityManager::mMario = ptr;

	} else if (entityType == EntityType::ground) {
		texture.loadFromFile("Media/Textures/Block.png");
		shared_ptr<Ground> groundPtr = make_shared<Ground>(texture, position);
		EntityManager::mGroundBlocks.push_back(groundPtr);

	} else {
		throw invalid_argument("Invalid argument. No entity type named : " + entityType);
	}
}

shared_ptr<Mario> EntityManager::GetMario() {
	return EntityManager::mMario;
}

vector<shared_ptr<Entity>> EntityManager::GetLadders()
{
	vector<shared_ptr<Entity>> ladders;
	return ladders;
}
