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
        Taxes
    };

    Case();
    Case(std::string const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size);
    ~Case();

    Type get_type() const;

private:
    sf::RectangleShape  _rect;
    sf::Font            _font;
    sf::Text            _country;
    Type                _type;
    std::string         _name;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif