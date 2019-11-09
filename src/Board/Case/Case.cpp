#include "Case.hpp"

Case::Case()
{
}

Case::Case(std::string const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size) :
    _rect(size),
    _type(type),
    _name(name)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    sf::Color c = sf::Color::White;
    switch (_type)
    {
    case Case::Type::Live:
        c = sf::Color::Red;
        break;
    case Case::Type::Goulag:
        c = sf::Color::Blue;
        break;
    case Case::Type::Propaganda:
        c = sf::Color::Green;
        break;
    case Case::Type::Education:
        c = sf::Color::Yellow;
        break;
    case Case::Type::Chance:
        c = sf::Color::White;
        break;
    case Case::Type::Taxes:
        c = sf::Color::White;
        break;
    }
    _rect.setFillColor(c);

    if (_font.loadFromFile(FONT_NODE_PATH))
	{
		_country.setFont(_font);
		_country.setFillColor(sf::Color::White);
		_country.setString(_name);
		_country.setStyle(sf::Text::Bold);
		_country.setCharacterSize(15);
        _country.setPosition(pos);
	}
}

Case::~Case()
{
}

Case::Type Case::get_type() const
{
    return _type;
}

void Case::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect);
    target.draw(_country);
}