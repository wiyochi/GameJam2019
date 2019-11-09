#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "UI/Button.hpp"

class MainMenu : public sf::Drawable
{
private:
	int _menu_code;
    Button *_start_button;
    Button *_help_button;
    Button *_quit_button; 
public:
	MainMenu();
    ~MainMenu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Window& window);
	int get_menu_code();
};

#endif
