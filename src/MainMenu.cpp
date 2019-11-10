#include "MainMenu.hpp"

MainMenu::MainMenu():
	_menu_code(0)
{
	_start_button = new Button(L"Nouvelle partie", sf::Vector2f(780, 250), sf::Vector2f(400, 100));
	_help_button = new Button(L"Aide", sf::Vector2f(780, 450), sf::Vector2f(400, 100));
	_quit_button = new Button(L"Quitter", sf::Vector2f(780, 650), sf::Vector2f(400, 100));
}

MainMenu::~MainMenu()
{
	delete _start_button;
	delete _help_button;
	delete _quit_button;
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_start_button, states);	
	target.draw(*_help_button, states);	
	target.draw(*_quit_button, states);	
}


void MainMenu::update(sf::Window& window)
{
	_start_button->update(window);
	_help_button->update(window);
	_quit_button->update(window);

	if (_help_button->is_clicked())
		_menu_code = 2;
	else if (_start_button->is_clicked())
		_menu_code = 1;
	else if (_quit_button->is_clicked())
		_menu_code = 3;
	
	//std::wcout << _menu_code << std::endl;
}


int MainMenu::get_menu_code()
{
	int code = _menu_code;
	if (_menu_code != 0)
		_menu_code = 0;
	return code;
}
