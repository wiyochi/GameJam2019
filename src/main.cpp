#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Board/Case/Case.hpp"
#include "Board/Board.hpp"

int main()
{
    
    Game g(20, 2);
    g.run();




/*
    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Board* b = new Board(sf::Vector2f(50.f, 50.f));

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*b);
        window.display();
    }

    delete b;

    return 0;
}