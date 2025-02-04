//
// Created by depre on 04/02/2025.
//

#include "CelestialObject.h"

CelestialObject::CelestialObject ()
{
    _mass = 10;
    _position = sf::Vector2f (100, 100);
    _velocity = sf::Vector2f (0, 0);
    _acceleration = sf::Vector2f (0, 0);
    _shape = sf::CircleShape(100);
    _shape.setFillColor (sf::Color::Black);
    _shape.setOrigin (_shape.getRadius (), _shape.getRadius ());
    _shape.setPosition (_position);
    _color = sf::Color::White;
}

CelestialObject::CelestialObject(const sf::Vector2f pos, const sf::Vector2f vel, const sf::Vector2f acc, const float mass, sf::Color color)
{
    _mass = mass;
    _position = pos;
    _velocity = vel;
    _acceleration = acc;
    _shape = sf::CircleShape(_mass);
    _shape.setFillColor(color);
    _shape.setOrigin (_shape.getRadius (), _shape.getRadius ());
    _shape.setPosition (_position);
    _color = color;
}

void CelestialObject::update()
{
    _velocity = _velocity + _acceleration;
    _position = _position + _velocity;
    _shape.setPosition (_position);
}