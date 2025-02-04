#include <SFML/Graphics.hpp>
#include "ObjectsManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(conf::maxScreenWidth, conf::maxScreenHeight), "Three Body");
    window.setFramerateLimit(60);

    ObjectsManager objects_manager = ObjectsManager(conf::nBodies);


    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        // UPDATE

        auto mousePosition = static_cast<sf::Vector2f>(sf::Vector2i(sf::Mouse::getPosition(window)));
        objects_manager.addAccel(mousePosition);
        objects_manager.update();

        // RENDER
        //objects_manager.draw(window);
        objects_manager.drawMesh(window);
        window.display();
        window.clear(sf::Color::Black);
    }
}