#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Board/Case/Case.hpp"
#include "Board/Board.hpp"
#include "UI/Button.hpp"
#include "MainMenu.hpp"

enum STATES {
    MAIN_MENU,
    HELP_MENU,
    GAME
};


int main()
{
    STATES state = GAME;
    
    Game g(20, 2);
   // g.run();





    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Board* b = new Board(sf::Vector2f(50.f, 50.f));
    MainMenu main_menu;

    Button* test_button = new Button(L"Test Bouton", sf::Vector2f(0.f, 0.f), sf::Vector2f(200.f, 50.f));

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
                test_button->update(window);

                if (test_button->is_clicked())
                    std::wcout << "TEST" << std::endl;

                // Draws
                window.clear();
                window.draw(*b);
                window.draw(*test_button);
                window.display();
                break;
            case MAIN_MENU:
                main_menu.update(window);
        }
    }

    delete b;

    return 0;
}