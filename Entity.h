#pragma once
#include "Textures.h"

using namespace std;

class Entity
{

protected:
	Entity();
	Entity(sf::Vector2f position);
public:
	Entity(sf::Vector2f position, string texturePath);

public:
	~Entity() { };

public:
	void GoRight(sf::Time elapsedTime);
	void GoLeft(sf::Time elapsedTime);
	bool ClimbLadder(sf::Time elapsedTime);
	void UpdateTexture(string path);
	bool GoDown(sf::Time elapsedTime);
	bool IsOnLadder();
	bool OnALadder();
	bool CollidesBlock();

public:
	bool GoesToTheRight = true;
	sf::Sprite mSprite;
	bool mEnabled = true;
	int mTimes = 0;
	float m_speed;

protected:
	sf::Texture mTexture;
	
};