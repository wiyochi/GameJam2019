#ifndef VIEW_H_
#define VIEW_H_

#include <SFML/Graphics.hpp>
#include "Case/Case.hpp"

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

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif