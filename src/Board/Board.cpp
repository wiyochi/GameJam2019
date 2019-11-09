#include "Board.hpp"

Board::Board()
{
}

Board::Board(sf::Vector2f pos, sf::Vector2f size) :
    _rect(size)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    for (size_t i = 0; i < NB_CASES; i++)
    {
        
    }
    
}

Board::~Board()
{
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    std::for_each(_cases.begin(), _cases.end(), [&](Case* c){ target.draw(*c, states); });
}