//
// Created by depre on 04/02/2025.
//

#ifndef CELESTIALOBJECT_H
#define CELESTIALOBJECT_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"


class CelestialObject {

public:
    CelestialObject ();
    CelestialObject (sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc, float mass, sf::Color color);

    void setAcceleration (const sf::Vector2f& acc) { _acceleration = acc; }
    void update ();

    sf::CircleShape getShape () { return _shape; }
    sf::Vector2f getAcc () const { return _acceleration; }
    sf::Vector2f getPos () const { return _position; }
    sf::Color getColor () const { return _color; }

private:
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
    float _mass;
    sf::CircleShape _shape;
    sf::Color _color;
};


#endif //CELESTIALOBJECT_H
