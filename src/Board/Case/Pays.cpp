#include "Pays.hpp"

Pays::Pays(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size) :
    Case(name, type, pos, size),
    _member_flat(1000000),
    _member_glob(1000000)
{
}

Pays::~Pays()
{
}

void Pays::set_member_flat(unsigned int nb)
{
    _member_flat = nb;
}

void Pays::set_member_glob(unsigned int nb)
{
    _member_glob = nb;
}

unsigned int Pays::get_member_flat() const
{
    return _member_flat;
}

unsigned int Pays::get_member_glob() const
{
    return _member_glob;
}