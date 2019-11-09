#include <SFML/Graphics.hpp>
#include "Board/Case/Case.hpp"
#include "Board/Board.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Board* b = new Board(sf::Vector2f(50.f, 50.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Updates
        b->update(window);

        // Draws
        window.clear();
        window.draw(*b);
        window.display();
    }

    delete b;

    return 0;
}