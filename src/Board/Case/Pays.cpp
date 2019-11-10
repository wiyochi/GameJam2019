#include "Pays.hpp"

Pays::Pays(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size, CaseLogic * case_logic) :
    Case(name, type, pos, size, case_logic)
{
}

Pays::~Pays()
{
}