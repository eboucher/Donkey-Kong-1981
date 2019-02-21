#pragma once
#include "Entity.h"

class Ground : public Entity
{
public:
	Ground(const sf::Texture&, sf::Vector2f);
	~Ground();
};

class Ladder : public Entity
{
public:
	Ladder(const sf::Texture&, sf::Vector2f);
	~Ladder();
};