#ifndef CASE_H_
#define CASE_H_

#include <string>
#include <SFML/Graphics.hpp>

constexpr char FONT_NODE_PATH[] = "resources/fonts/Roboto-Thin.ttf";


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

protected:
    sf::RectangleShape  _rect;
    sf::Font            _font;
    sf::Text            _country;
    Type                _type;
    std::wstring        _name;

    static bool         left_click_pressed;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif