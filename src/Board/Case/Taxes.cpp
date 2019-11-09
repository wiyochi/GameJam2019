#include "Taxes.hpp"

Taxes::Taxes() :
    Case(L"Taxes", Case::Type::Taxes, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Taxes::Taxes(sf::Vector2f const & pos, sf::Vector2f const & size) :
    Case(L"Taxes", Case::Type::Taxes, pos, size)
{
}

Taxes::~Taxes()
{
}
