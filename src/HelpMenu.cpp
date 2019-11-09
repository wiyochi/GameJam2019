#include "HelpMenu.hpp"

HelpMenu::HelpMenu():
	_back_button(new Button(L"Retour", sf::Vector2f(200, 100), sf::Vector2f(400, 100))), _back(false)
{
}

HelpMenu::~HelpMenu()
{
	delete _back_button;
}

void HelpMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_back_button, states);
}


void HelpMenu::update(sf::Window& window)
{
	_back_button->update(window);

	if (_back_button->is_clicked())
		_back = true;
	
}


bool HelpMenu::get_back()
{
	if (_back)
	{
		_back = false;
		return true;
	}

	return false;

}