#include "Button.hpp"

bool Button::left_click_pressed = false;

Button::Button(std::wstring const & name, sf::Vector2f const & pos, sf::Vector2f const & size, sf::Color c) :
    _rect(size),
    _name(name),
    _rect_color(c),
    _rect_color_clicked(c)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(2);
    sf::Color outline(_rect_color);
    outline.a = 150;
    _rect.setOutlineColor(outline);
    _rect.setFillColor(_rect_color);

    _rect_color_clicked.a = 150;

    if (_font.loadFromFile(FONT_PATH))
	{
		_text.setFont(_font);
		_text.setFillColor(sf::Color::Black);
		_text.setString(_name);
		_text.setStyle(sf::Text::Bold);
		_text.setCharacterSize(15);

        sf::Rect size_text = _text.getGlobalBounds();
        _text.setPosition(sf::Vector2f(pos.x + size.x / 2 - size_text.width / 2, pos.y + size.y / 2 - size_text.height / 2));
	}
}

Button::~Button()
{
}

void Button::update(sf::Window& window)
{
    sf::Vector2f mouse_pos(sf::Mouse::getPosition(window));
    if (_rect.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !left_click_pressed)
    {
        std::wcout << L"Button clicked: " << _name << std::endl;
        left_click_pressed = true;
        _rect.setFillColor(_rect_color_clicked);
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && left_click_pressed)
    {
        left_click_pressed = false;
        _rect.setFillColor(_rect_color);
        _clicked = true;
    }
}

bool Button::is_clicked()
{
    bool tmp = _clicked;
    if (_clicked)
    {
        _clicked = false;
    }
    return tmp;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    target.draw(_text, states);
}