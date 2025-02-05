//
// Created by depre on 04/02/2025.
//

#include "CelestialObject.h"

#include "config.hpp"

CelestialObject::CelestialObject ()
{
    _mass = 10;
    _position = sf::Vector2<double> (100, 100);
    _velocity = sf::Vector2<double> (0, 0);
    _acceleration = sf::Vector2<double> (0, 0);
    _color = sf::Color::White;
    _shape = sf::CircleShape (std::sqrt(_mass)*10);
    _shape.setFillColor (_color);
    _shape.setOrigin (_shape.getRadius (), _shape.getRadius ());
    _shape.setPosition ({static_cast<float>(_position.x), static_cast<float>(_position.y)});
}

CelestialObject::CelestialObject(const double x, const double y, const double mass)
{
    _mass = mass;
    _position = sf::Vector2<double> (x, y);
    _velocity = sf::Vector2<double> (0, 0);
    _acceleration = sf::Vector2<double> (0, 0);
    _color = sf::Color::Blue;
    _shape = sf::CircleShape (std::sqrt(_mass)*10);
    _shape.setFillColor (_color);
    _shape.setOrigin (_shape.getRadius (), _shape.getRadius ());
    _shape.setPosition ({static_cast<float>(_position.x), static_cast<float>(_position.y)});
}

CelestialObject::CelestialObject(const sf::Vector2<double> pos, const sf::Vector2<double> vel, const sf::Vector2<double> acc, const double mass, sf::Color color)
{
    _mass = mass;
    _position = pos;
    _velocity = vel;
    _acceleration = acc;
    _shape = sf::CircleShape (std::sqrt(_mass)*10);
    _shape.setFillColor(color);
    _shape.setOrigin (_shape.getRadius (), _shape.getRadius ());
    _shape.setPosition ({static_cast<float>(_position.x), static_cast<float>(_position.y)});
    _color = color;
}

void CelestialObject::update()
{
    _velocity = _velocity + _acceleration;
    Vector2Df newVel = {static_cast<float>(_velocity.x), static_cast<float>(_velocity.y)};
    newVel.limit(conf::maxSpeed);
    _velocity = {newVel.x, newVel.y};
    _position = _position + _velocity;
    _shape.setPosition ({static_cast<float>(_position.x), static_cast<float>(_position.y)});

    _trail.push_back(_position);
    if (_trail.size() > conf::maxTrailLength) _trail.pop_front();
}

void CelestialObject::draw(sf::RenderWindow& window) const
{
    sf::VertexArray trailVA(sf::LineStrip, _trail.size());
    for (size_t i = 0; i < _trail.size(); ++i) {
        const unsigned char alpha = 255 * (double(i) / conf::maxTrailLength);  // Fade effect
        trailVA[i] = sf::Vertex({static_cast<float>(_trail[i].x), static_cast<float>(_trail[i].y)}, sf::Color(_color.r, _color.g, _color.b, alpha));
    }
    window.draw(trailVA);
    window.draw(_shape);
}

void CelestialObject::attract (CelestialObject& other)
{
    // Find the direction of the force (vector)
    sf::Vector2<double> force = _position - other._position;
    Vector2Df direction = Vector2Df(force.x, force.y);

    // Find the distance between the objects
    const double distance = direction.getMagnitude();

    // Calculate the strength of the force
    const double strength = (conf::gravitationalConstant * _mass) / (distance);

    // Apply the strength to the direction found
    direction.setMagnitude(strength);

    force = {direction.x, direction.y};
    // Apply the force
    other.setAcceleration(force);
    other.update();
}
