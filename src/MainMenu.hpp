#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class MainMenu : public sf::Drawable
{
private:
	int _menu_code;
    sf::RectangleShape _rect;
    sf::Font _font;
    sf::Text _text;
    static bool         left_click_pressed;
public:
	MainMenu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Window& window);
	int get_menu_code() const;
};

#endif
