#pragma once
#include "EntityManager.h"
using namespace std;

class Mario
{
  public:
	Mario(const sf::Texture&, sf::Vector2f);
	~Mario();

  private:
	bool isMovingRight = false;
	bool isMovingLeft = false;
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isOnLadder = false;
	bool isJumping = false;
	bool isFalling = false;
};