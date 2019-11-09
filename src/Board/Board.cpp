#include "Board.hpp"

Board::Board(sf::Vector2f pos)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    sf::Vector2f cases_size(CASES_X[1] - CASES_X[0], CASES_Y[NB_CASES - 1] - CASES_Y[0]);
    _rect.setSize(sf::Vector2f(cases_size.x * (NB_CASES / 4 + 1), cases_size.y * (NB_CASES / 4 + 1)));
    for (size_t i = 0; i < NB_CASES; i++)
    {
        switch (CASES_TYPES[i])
        {
        case Case::Chance:
            _cases[i] = new Chance(sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        case Case::Taxes:
            _cases[i] = new Taxes(sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        default:
            _cases[i] = new Case(std::wstring(CASES_NAMES[i]), CASES_TYPES[i], sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        }
    }
    
}

Board::~Board()
{
    // probleme a regle
    //std::for_each(_cases.begin(), _cases.end(), [](Case** c){ if (*c) delete *c; });
    // for (auto i = _cases.begin(); i != _cases.end(); i++)
    // {
    //     delete *i;
    // }
    
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    std::for_each(_cases.begin(), _cases.end(), [&](Case* c){ target.draw(*c, states); });
}