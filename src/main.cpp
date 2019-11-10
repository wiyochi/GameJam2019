#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Board/Case/Case.hpp"
#include "Board/Board.hpp"
#include "UI/Button.hpp"
#include "MainMenu.hpp"
#include "HelpMenu.hpp"

enum STATES {
    MAIN_MENU,
    HELP_MENU,
    GAME
};


int main()
{
    STATES state = MAIN_MENU;

    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Monop mais pas monop");
    sf::View v;
    
    Board* b = new Board(sf::Vector2f(0.f, 0.f));
    MainMenu* main_menu = new MainMenu();
    HelpMenu* help_menu = new HelpMenu();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta > 0)
                    v.zoom(0.9f);
                else
                    v.zoom(1.1f);
            }
        }

        //window.setView(v);

        window.clear();
        int code;
        switch(state)
        {
            case GAME:
                // Updates
                b->update(window);
                
                // Draws
                window.draw(*b);
                break;
            case MAIN_MENU:
                main_menu->update(window);
                code = main_menu->get_menu_code();
                if (code == 1)
                    state = GAME;
                else if (code == 2)
                    state = HELP_MENU;
                else if (code == 3)
                    window.close();

                window.draw(*main_menu);
                break;
            case HELP_MENU:
                help_menu->update(window);
                window.draw(*help_menu);
                if (help_menu->get_back())
                    state = MAIN_MENU;
                break;
        }

        window.display();
    }

    delete b;

    return 0;
}