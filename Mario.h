#pragma once
#include "EntityManager.h"
using namespace std;

class Mario :
	public Entity
{
  public:
	Mario(const sf::Texture&, sf::Vector2f);
	~Mario();

  public:  // TODO: This in fact has to be private, not public
	static const float MarioSpeed;
	static const bool isMovingRight = false;
	static const bool isMovingLeft = false;
	static const bool isMovingUp = false;
	static const bool isMovingDown = false;
	static const bool isOnLadder = false;
	static const bool isJumping = false;
	static bool isFalling;

  protected:
	  bool StandsOnGround();

  public:
	  static void setFalling(bool);
	  static void UpdateMario(sf::Time elapsedTime);
};