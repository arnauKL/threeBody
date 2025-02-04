//
// Created by depre on 04/02/2025.
//

#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H
#include "CelestialObject.h"
#include "utils/Random.h"
#include "config.hpp"
#include "utils/Vector2Df.h"
#include <SFML/Graphics.hpp>

class ObjectsManager {

public:
    explicit ObjectsManager(const int& count);

    void update();
    void addAccel(sf::Vector2f source);

    void draw(sf::RenderWindow& window);
    void drawMesh(sf::RenderWindow& window);

private:
    int _objectCount;
    std::vector<CelestialObject> _objects;
    Random _random;
    sf::VertexArray _vertexArray;
};

#endif //OBJECTSMANAGER_H
