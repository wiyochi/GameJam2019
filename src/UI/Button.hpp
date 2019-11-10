#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

extern const char FONT_PATH[];

class Button : public sf::Drawable
{
public:
    Button(std::wstring const & name, sf::Vector2f const & pos, sf::Vector2f const & size, sf::Color normal_color = sf::Color::White, sf::Color clicked_color = sf::Color::Black, sf::Color disable_color = sf::Color::Red);
    ~Button();

    void set_active(bool state);
    void update(sf::Window& window);
    bool is_clicked();

private:
    sf::RectangleShape  _rect;
    sf::Font            _font;
    sf::Text            _text;
    std::wstring        _name;
    bool _is_active;
    bool                _clicked;

    sf::Color           _rect_color;
    sf::Color           _rect_color_clicked;
    sf::Color           _rect_disable;

    static bool         left_click_pressed;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif