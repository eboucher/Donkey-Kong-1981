#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum EntityType
{
	player,
	ground,
	ladder
};

class Entity
{
  public:
	Entity() { };
	Entity(const EntityType entityType, 
		   const sf::Texture texture, 
		   const sf::Vector2f initialPos);
	~Entity() { };

  public:
	sf::Sprite m_sprite;
	sf::Vector2u m_size;
	sf::Vector2f m_position;
	sf::Texture m_texture;
	EntityType m_type;
	bool m_enabled = true;

	// Enemy only
	bool m_bLeftToRight = true;
	int m_times = 0;
};

