//
// Created by depre on 04/02/2025.
//

#include "Vector2Df.h"

float Vector2Df::getMagnitude() const {
    return std::sqrt(x * x + y * y);
}

// Function to set the magnitude
void Vector2Df::setMagnitude(const float magnitude) {
    const float currentMagnitude = getMagnitude();
    const float scale = magnitude / currentMagnitude;
    x *= scale;
    y *= scale;
}