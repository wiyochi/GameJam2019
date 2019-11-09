#include "MainMenu.hpp"

MainMenu::MainMenu()
{
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}


void MainMenu::update(sf::Window& window)
{
   sf::Vector2f mouse_pos(sf::Mouse::getPosition(window));
    if (_rect.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !left_click_pressed)
    {
        std::cout << _text << std::endl;
        left_click_pressed = true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && left_click_pressed)
    {
        left_click_pressed = false;
    }
}


int MainMenu::get_menu_code() const
{

}
