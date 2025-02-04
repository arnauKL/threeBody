//
// Created by depre on 04/02/2025.
//

#ifndef VECTOR2DF_H
#define VECTOR2DF_H
#include "SFML/System/Vector2.hpp"
#include <cmath>

class Vector2Df : public sf::Vector2f{
public:
    float getMagnitude () const;
    void setMagnitude(float magnitude);
};



#endif //VECTOR2DF_H
