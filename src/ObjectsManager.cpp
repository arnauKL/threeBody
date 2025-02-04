//
// Created by depre on 04/02/2025.
//

#include "ObjectsManager.h"

ObjectsManager::ObjectsManager (const int& count)
{
    _objectCount = count;
    for (int i = 0; i < _objectCount; i++)
    {
        const sf::Color color = sf::Color{_random.rndUchar(),_random.rndUchar(), _random.rndUchar()};
        const sf::Vector2f vel = sf::Vector2f{_random.rndFloat(-conf::maxInitSpeed, conf::maxInitSpeed),_random.rndFloat(-conf::maxInitSpeed, conf::maxInitSpeed)};
        CelestialObject a = CelestialObject({_random.rndFloat()*conf::maxScreenWidth, _random.rndFloat()*conf::maxScreenHeight},{vel.x, vel.y},{0,0}, _random.rndFloat()*conf::maxMass, color);
        _objects.push_back(a);
    }
    _vertexArray = sf::VertexArray(sf::Points, _objectCount);
}

void ObjectsManager::update()
{
    for (int i = 0; i < _objectCount; i++)
    {
        // Calculate new acceleration
        //_objects[i].setAcceleration({0,0});
        // Update the rest
        _objects[i].update ();
    }
}

void ObjectsManager::addAccel (const sf::Vector2f source)
{
    for (int i = 0; i < _objectCount; i++)
    {
        Vector2Df acc = {source - _objects[i].getPos()};
        acc.setMagnitude(0.05f);
        sf::Vector2f newAcc = sf::Vector2f{acc.x,acc.y};
        _objects[i].setAcceleration(newAcc);
    }
}


void ObjectsManager::draw (sf::RenderWindow& window)
{
    for (int i = 0; i < _objectCount; i++)
    {
        window.draw(_objects[i].getShape());
    }
}

void ObjectsManager::drawMesh (sf::RenderWindow& window)
{
    for (int i = 0; i < _objectCount; i++)
    {
        _vertexArray[i].position = _objects[i].getPos();
        _vertexArray[i].color = _objects[i].getColor();
    }
    window.draw(_vertexArray);
}

