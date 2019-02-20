#pragma once
#include "EntityManager.h"
#include "Entity.h"
using namespace std;

class Mario :
	public Entity
{
  public:
	Mario(const sf::Texture&, sf::Vector2f);
	~Mario();

  private:
	static float MarioSpeed;
	static bool isMovingRight;
	static bool isMovingLeft;
	static bool isMovingUp;
	static bool isMovingDown;
	static bool isOnLadder;
	static bool isJumping;
	static bool isFalling;

  protected:
	  bool StandsOnGround();

  public:
	  static void setFalling(bool);
	  static void HandleInput(sf::Keyboard::Key key, bool isPressed);
	  static void UpdateMario(sf::Time elapsedTime);
};