#include "pch.h"
#include "Entity.h"

Entity::Entity() {

}

void Entity::setInitialX(float value)
{
	_initialX = value;
}

void Entity::setInitialY(float value)
{
	_initialY = value;
}

void Entity::setTexture(string texture)
{
	_texture = texture;
}
