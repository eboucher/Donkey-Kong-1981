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
	static void SetMario(sf::Vector2f position);
	static shared_ptr<Mario> GetMario();
	static void AddGroundBlock(sf::Vector2f position);
	static vector<shared_ptr<Ground>> GetGroundBlocks();
	static void AddLadder(sf::Vector2f position);
	static vector<shared_ptr<Entity>> GetLadders();

  public:
	static void UpdateEntities(sf::Time elapsedTime);
};

