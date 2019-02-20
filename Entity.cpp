#include "pch.h"
#include "Entity.h"

Entity::Entity(const EntityType entityType,
			   const sf::Texture texture,
	           const sf::Vector2f initialPos) {
	m_type = entityType;
	m_texture = texture;
	m_sprite.setPosition(initialPos);
}