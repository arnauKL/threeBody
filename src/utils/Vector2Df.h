//
// Created by depre on 04/02/2025.
//

#ifndef VECTOR2DF_H
#define VECTOR2DF_H
#include "SFML/System/Vector2.hpp"
#include <cmath>

class Vector2Df : public sf::Vector2f{
public:
    Vector2Df(float x, float y) : sf::Vector2f(x, y){};
    float getMagnitude () const;
    void setMagnitude(float magnitude);
    void limit(float maxMagnitude);
};



#endif //VECTOR2DF_H
