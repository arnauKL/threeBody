//
// Created by depre on 04/02/2025.
//

#ifndef CELESTIALOBJECT_H
#define CELESTIALOBJECT_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <deque>

#include "SFML/Graphics/RenderWindow.hpp"
#include "utils/Vector2Df.h"

class CelestialObject {

public:
    CelestialObject ();
    CelestialObject (double x, double y, double mass);
    CelestialObject (sf::Vector2<double> pos, sf::Vector2<double> vel, sf::Vector2<double> acc, double mass, sf::Color color);

    void setAcceleration (const sf::Vector2<double>& acc) { _acceleration = acc; }
    void update ();
    void attract (CelestialObject& other);
    void draw (sf::RenderWindow& window) const;

    sf::CircleShape getShape () { return _shape; }
    sf::Vector2<double> getAcc () const { return _acceleration; }
    sf::Vector2<double> getPos () const { return _position; }
    sf::Color getColor () const { return _color; }

private:
    sf::Vector2<double> _position;
    sf::Vector2<double> _velocity;
    sf::Vector2<double> _acceleration;
    double _mass;
    sf::CircleShape _shape;
    sf::Color _color;
    std::deque<sf::Vector2<double>> _trail;
};


#endif //CELESTIALOBJECT_H
