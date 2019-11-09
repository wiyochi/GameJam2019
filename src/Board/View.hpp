#ifndef VIEW_H_
#define VIEW_H_

#include <SFML/Graphics.hpp>
#include "Case/Case.hpp"

extern const char FONT_PATH[];

class View : public sf::Drawable
{
public:
    View(sf::Vector2f const & pos, sf::Vector2f const & size);
    ~View();

    void set_case(Case* c);
    Case* get_case();

private:
    sf::RectangleShape  _rect;
    Case*               _case;
    sf::Font            _font;
    sf::Text            _text_title;
    sf::Text            _text_center;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif