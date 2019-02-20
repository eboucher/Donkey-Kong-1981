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
	bool isMovingRight = false;
	bool isMovingLeft;
	bool isMovingUp;
	bool isMovingDown;
	bool isOnLadder;
	bool isJumping;
	bool isFalling;

  protected:
	  bool StandsOnGround();

  public:
	  void setFalling(bool);
	  void HandleInput(sf::Keyboard::Key key, bool isPressed);
	  void UpdateMario(sf::Time elapsedTime);
};