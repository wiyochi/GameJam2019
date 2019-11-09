#ifndef HELPMENU_HPP_
#define HELPMENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "UI/Button.hpp"

class HelpMenu : public sf::Drawable
{
private:
	Button * _back_button;
	bool _back;
public:
	HelpMenu();
	~HelpMenu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Window& window);
	bool get_back();
};

#endif
