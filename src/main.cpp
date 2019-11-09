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
    
    Game g(20, 2);
   // g.run();





    sf::RenderWindow window(sf::VideoMode(800, 800), "Monop mais pas monop");
    
    Board* b = new Board(sf::Vector2f(50.f, 50.f));
    MainMenu* main_menu = new MainMenu();
    HelpMenu* help_menu = new HelpMenu();

    Button* test_button = new Button(L"Test Bouton", sf::Vector2f(0.f, 0.f), sf::Vector2f(200.f, 50.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        int code;
        switch(state)
        {
            case GAME:
                // Updates
                b->update(window);
                test_button->update(window);

                if (test_button->is_clicked())
                    std::wcout << "TEST" << std::endl;

                // Draws
                window.draw(*b);
                window.draw(*test_button);
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