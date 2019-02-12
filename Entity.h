#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum EntityType
{
	player,
	block,
	ladder
};

class Entity
{
  public:
	Entity() { };

	void setInitialX(float value);
	void setInitialY(float value);
	void setTexture(string texture);

	~Entity() { };

  public:
	sf::Sprite m_sprite;
	sf::Vector2u m_size;
	sf::Vector2f m_position;
	sf::Texture texture;
	EntityType m_type;
	float _initialX;
	float _initialY;
	string _texture;
	bool m_enabled = true;

	// Enemy only
	bool m_bLeftToRight = true;
	int m_times = 0;
};

