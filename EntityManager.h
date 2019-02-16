#pragma once
#include "Entity.h"
#include "Mario.h"
#include "InanimateObjects.h"

#define defaultPosition sf::Vector2f(0, 0)

using namespace std;

class EntityManager
{
  public:
	EntityManager();
	~EntityManager();

  private:
	static shared_ptr<Mario> mMario;
	static vector<shared_ptr<Ground>> mGroundBlocks;
	static vector<shared_ptr<Ladder>> mLadders;

  public:
	static void addNewEntity(const EntityType, sf::Vector2f position = defaultPosition);
	static shared_ptr<Entity> GetMario();
	static vector<shared_ptr<Ground>> GetGroundBlocks();
	static vector<shared_ptr<Entity>> GetLadders();
};

