#include "View.hpp"

View::View(sf::Vector2f const & pos, sf::Vector2f const & size) :
    _rect(size)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    if (_font.loadFromFile(FONT_PATH))
	{
		_text_title.setFont(_font);
		_text_title.setFillColor(sf::Color::White);
		_text_title.setStyle(sf::Text::Bold);
		_text_title.setCharacterSize(15);
        _text_title.setPosition(pos);
	}
}

View::~View()
{
}

void View::set_case(Case* c)
{
    _case = c;
}

Case* View::get_case()
{
    return _case;
}

void View::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
}