#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr char FONT_PATH[] = "resources/fonts/Roboto-Thin.ttf";

class Button : public sf::Drawable
{
public:
    Button(std::wstring const & name, sf::Vector2f const & pos, sf::Vector2f const & size, sf::Color c = sf::Color::White);
    ~Button();

    void update(sf::Window& window);
    bool is_clicked();

private:
    sf::RectangleShape  _rect;
    sf::Font            _font;
    sf::Text            _text;
    std::wstring        _name;
    bool                _clicked;

    sf::Color           _rect_color;
    sf::Color           _rect_color_clicked;

    static bool         left_click_pressed;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif