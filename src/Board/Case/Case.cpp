#include "Case.hpp"

bool Case::left_click_pressed = false;

Case::Case()
{
}

Case::Case(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size) :
    _rect(sf::Vector2f(size.x - 2, size.y - 2)),
    _type(type),
    _name(name)
{
    _rect.setPosition(sf::Vector2f(pos.x + 1, pos.y + 1));
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
        c = sf::Color(40, 40, 40);
        break;
    case Case::Type::Taxes:
        c = sf::Color(40, 40, 40);
        break;
    case Case::Type::USA:
        c = sf::Color(40, 40, 40);
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

void Case::update(sf::Window& window)
{
    sf::Vector2f mouse_pos(sf::Mouse::getPosition(window));
    if (_rect.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !left_click_pressed)
    {
        std::wcout << _name << std::endl;
        set_viewed(true);
        left_click_pressed = true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && left_click_pressed)
    {
        left_click_pressed = false;
    }
}

void Case::set_viewed(bool b)
{
    _viewed = b;
}

bool Case::get_viewed() const
{
    return _viewed;
}

std::wstring const & Case::get_name() const
{
    return _name;
}

void Case::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    target.draw(_country, states);
}