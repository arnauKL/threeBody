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
        const sf::Vector2<double> vel = sf::Vector2<double>{_random.rndFloat(-conf::maxInitSpeed, conf::maxInitSpeed),_random.rndFloat(-conf::maxInitSpeed, conf::maxInitSpeed)};
        const sf::Vector2<double> pos = sf::Vector2<double>{_random.rndFloat(0, conf::maxScreenWidth), _random.rndFloat(0,conf::maxScreenHeight)};
        CelestialObject a = CelestialObject({pos.x, pos.y},{vel.x, vel.y},{0,0}, _random.rndFloat()*conf::maxMass, color);
        _objects.push_back(a);
    }
    /*
    _objects.emplace_back(CelestialObject({(conf::maxScreenWidth/2)+150, conf::maxScreenHeight/2},{0,2},{0,0}, 5, sf::Color::White));
    _objects.emplace_back(CelestialObject({(conf::maxScreenWidth/2)-150, conf::maxScreenHeight/2},{0,-4},{0,0}, 5, sf::Color::White));
    _objects.emplace_back(CelestialObject({(conf::maxScreenWidth/2), conf::maxScreenHeight/2},{1,-1},{0,0}, 5, sf::Color::White));*/
    _vertexArray = sf::VertexArray(sf::Points, _objectCount);
}

void ObjectsManager::update()
{
    CelestialObject c = CelestialObject(conf::maxScreenWidth/2, conf::maxScreenHeight/2, 5);
    for (int i = 0; i < _objectCount; i++)
    {
        c.attract(_objects[i]);
        for (int j = 0; j < _objectCount; j++)
        {
            if (i != j)
            {
                _objects[i].attract(_objects[j]);
            }
        }
    }
}

void ObjectsManager::addAccel (const sf::Vector2<double> source)
{
    for (int i = 0; i < _objectCount; i++)
    {
        const sf::Vector2<double> tmp = {source - _objects[i].getPos()};
        Vector2Df acc = Vector2Df{static_cast<float>(tmp.x), static_cast<float>(tmp.y)};
        acc.setMagnitude(0.05f);
        sf::Vector2<double> newAcc = sf::Vector2<double>{acc.x,acc.y};
        _objects[i].setAcceleration(newAcc);
    }
}


void ObjectsManager::draw (sf::RenderWindow& window) const
{
    for (int i = 0; i < _objectCount; i++)
    {
        _objects[i].draw(window);
    }
}

void ObjectsManager::drawMesh (sf::RenderWindow& window)
{
    for (int i = 0; i < _objectCount; i++)
    {
        _vertexArray[i].position = {static_cast<float>(_objects[i].getPos().x), static_cast<float>(_objects[i].getPos().y)};
        _vertexArray[i].color = _objects[i].getColor();
        //_vertexArray[i].color = sf::Color::White;
    }
    window.draw(_vertexArray);
}

