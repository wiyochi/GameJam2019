#ifndef CASE_H_
#define CASE_H_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

extern const char FONT_PATH[];
extern const char TEXTURE_PATH[];

class Case : public sf::Drawable
{
public:
    enum Type
    {
        Live,
        Goulag,
        Propaganda,
        Education,
        Chance,
        Taxes,
        USA
    };

    Case();
    Case(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size);
    ~Case();

    Type get_type() const;
    virtual void update(sf::Window& window);
    void set_viewed(bool b);
    bool get_viewed() const;
    std::wstring const & get_name() const;
    sf::RectangleShape& get_rect();
    void rotate(float angle);

protected:
    sf::Texture         _texture;
    sf::RectangleShape  _rect;
    sf::Font            _font;
    sf::Text            _country;
    Type                _type;
    std::wstring        _name;
    bool                _viewed;

    static bool         left_click_pressed;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif