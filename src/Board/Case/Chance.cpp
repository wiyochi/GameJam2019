#include "Chance.hpp"

Chance::Chance() :
    Case(L"Chance", Case::Type::Chance, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Chance::Chance(sf::Vector2f const & pos, sf::Vector2f const & size) :
    Case(L"Chance", Case::Type::Chance, pos, size)
{
}

Chance::~Chance()
{
}
