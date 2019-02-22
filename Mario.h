#pragma once
#include "Entity.h"

constexpr auto DEFAULT_SPEED = 100.f;;

using namespace std;

class Mario :
	public Entity
{
  public:
	Mario(const sf::Texture&, sf::Vector2f);
	//~Mario();

  private:
	float MarioSpeed;
	bool isMovingRight = false;
	bool isMovingLeft = false;
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isOnLadder = false;
	bool isJumping = false;
	bool isFalling = false;

  protected:
	  bool StandsOnGround();

  public:
	  void setFalling(bool value);
	  void HandleInput(sf::Keyboard::Key key, bool isPressed);
	  void UpdateMario(sf::Time elapsedTime);
};