#pragma once
#include "Entity.h"
#include "Mario.h"
#include "InanimateObjects.h"
using namespace std;

class EntityManager
{
  public:
	EntityManager();
	~EntityManager();

  public:
	static vector<shared_ptr<Entity>> m_Entities;
	static shared_ptr<Mario> m; // TODO! (SO FAR THIS IS WRONG)
	static vector<shared_ptr<Ground>> mGround;
	static vector<shared_ptr<Ladder>> mLadders;
	static shared_ptr<Entity> GetPlayer();
	static vector<shared_ptr<Entity>> GetLadders();
};

