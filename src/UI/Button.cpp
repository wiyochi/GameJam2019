#include "Button.hpp"

bool Button::left_click_pressed = false;

Button::Button(std::wstring const & name, sf::Vector2f const & pos, sf::Vector2f const & size, sf::Color normal_color, sf::Color clicked_color, sf::Color disable_color) :
    _rect(size),
    _name(name),
    _is_active(true),
    _clicked(false),
    _rect_color(normal_color),
    _rect_color_clicked(clicked_color),
    _rect_disable(disable_color)
{
    _rect.setPosition(pos);
   // _rect.setOutlineThickness(2);
    sf::Color outline(_rect_color);
    outline.a = 150;
    _rect.setOutlineColor(outline);
    _rect.setFillColor(_rect_color);

    if (_font.loadFromFile(FONT_PATH))
	{
		_text.setFont(_font);
		_text.setFillColor(sf::Color::White);
		_text.setString(_name);
		_text.setStyle(sf::Text::Bold);
		_text.setCharacterSize(25);

        sf::Rect size_text = _text.getGlobalBounds();
        _text.setPosition(sf::Vector2f(pos.x + size.x / 2 - size_text.width / 2, pos.y + size.y / 2 - size_text.height / 2));
	}
    _texture.loadFromFile("resources/textures/frame.png");
    _rect.setTexture(&_texture);
}

Button::~Button()
{
    
}

void Button::set_active(bool state)
{
    _is_active = state;
    if (state)
        _rect.setFillColor(_rect_color);
    else
        _rect.setFillColor(_rect_disable);
    
}

void Button::update(sf::Window& window)
{
    if (_is_active)
    {
        sf::Vector2f mouse_pos(sf::Mouse::getPosition(window));
        if (_rect.getGlobalBounds().contains(mouse_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !left_click_pressed)
        {
        // std::wcout << L"Button clicked: " << _name << " (" << mouse_pos.x << ";" << mouse_pos.y << ")" << std::endl;
            left_click_pressed = true;
            _rect.setFillColor(_rect_color_clicked);
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && left_click_pressed && _rect.getGlobalBounds().contains(mouse_pos))
        {
            left_click_pressed = false;
            _rect.setFillColor(_rect_color);
            _clicked = true;
        }
    }
}

bool Button::is_clicked()
{
    if (_clicked)
    {
        _clicked = false;
        return true;
    }
    return false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (_is_active)
    {
        target.draw(_rect, states);
        target.draw(_text, states);
    }
    
}