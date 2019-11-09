#include "Case.hpp"

const char FONT_PATH[] = "resources/fonts/Roboto-Thin.ttf";
const char TEXTURE_PATH[] = "resources/textures/";

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

    std::string path(TEXTURE_PATH);
    sf::Color c = sf::Color::White;

    switch (_type)
    {
    case Case::Type::Live:
        c = sf::Color::Red;
        path.append("card_red.png");
        break;
    case Case::Type::Goulag:
        c = sf::Color::Blue;
        path.append("card_blue.png");
        break;
    case Case::Type::Propaganda:
        c = sf::Color::Green;
        path.append("card_green.png");
        break;
    case Case::Type::Education:
        c = sf::Color::Yellow;
        path.append("card_yellow.png");
        break;
    case Case::Type::Chance:
        c = sf::Color(40, 40, 40);
        path.append("card_purple.png");
        break;
    case Case::Type::Taxes:
        c = sf::Color(40, 40, 40);
        path.append("card_purple.png");
        break;
    case Case::Type::USA:
        c = sf::Color(40, 40, 40);
        path.append("card_purple.png");
        break;
    }
    //_rect.setFillColor(c);

    if (_font.loadFromFile(FONT_PATH))
	{
		_country.setFont(_font);
		_country.setFillColor(sf::Color::White);
		_country.setString(_name);
		_country.setStyle(sf::Text::Bold);
		_country.setCharacterSize(15);
        _country.setPosition(pos);
	}

    
    if (_texture.loadFromFile(path))
    {
        _rect.setTexture(&_texture);
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

sf::RectangleShape& Case::get_rect()
{
    return _rect;
}

void Case::rotate(float angle)
{
    _rect.rotate(angle);
    _country.rotate(angle);
}

void Case::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    target.draw(_country, states);
}