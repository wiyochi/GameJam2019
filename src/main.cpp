#include <SFML/Graphics.hpp>
#include "Board/Case/Case.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Case* c1 = new Case("France", Case::Type::Propaganda, sf::Vector2f(50.f, 50.f), sf::Vector2f(50.f, 50.f));
    Case* c2 = new Case("Russie", Case::Type::Goulag, sf::Vector2f(100.f, 50.f), sf::Vector2f(50.f, 50.f));
    Case* c3 = new Case("Mongolie", Case::Type::Education, sf::Vector2f(150.f, 50.f), sf::Vector2f(50.f, 50.f));
    Case* c4 = new Case("Paraguay", Case::Type::Live, sf::Vector2f(200.f, 50.f), sf::Vector2f(50.f, 50.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*c1);
        window.draw(*c2);
        window.draw(*c3);
        window.draw(*c4);
        window.display();
    }

    return 0;
}