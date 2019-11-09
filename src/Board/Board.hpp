#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "Case/Case.hpp"

constexpr unsigned int NB_CASES = 20;
constexpr char*        COUNTRY_NAMES[NB_CASES - 4] = {
    "Le timor oriental", "France" , "Pologne", "Mongolie",
    "Mexique", "US", "Corée du nord", "Japon", "Allemagne",
    "Australie", "Paraguay", "Perou", "Egypte", "Russie",
    "Nouvelle Zelande", "Chine"
};

class Board : public sf::Drawable
{
public:
    Board();
    Board(sf::Vector2f pos, sf::Vector2f size);
    ~Board();

private:
    sf::RectangleShape              _rect;
    std::array<Case*, NB_CASES>     _cases;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif