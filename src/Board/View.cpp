#include "View.hpp"

View::View(sf::Vector2f const & pos, sf::Vector2f const & size) :
    _rect(size)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);
}

View::~View()
{
}

void View::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
}