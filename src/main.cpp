#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Board/Case/Case.hpp"
#include "Board/Board.hpp"
#include "MainMenu.hpp"

enum STATES {
    MAIN_MENU,
    HELP_MENU,
    GAME
};


int main()
{
    STATES state = MAIN_MENU;
    
    Game g(20, 2);
   // g.run();





    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Board* b = new Board(sf::Vector2f(50.f, 50.f));
    MainMenu main_menu;


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
        switch(state)
        {
            case GAME:
                // Updates
                b->update(window);

                // Draws
                window.clear();
                window.draw(*b);
                window.display();
                  break;
            case MAIN_MENU:
                main_menu.update(window);
        }
    }

    delete b;

    return 0;
}