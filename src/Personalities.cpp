#include "Personalities.hpp"

Personalities::Personalities():
	 _owners({-1, -1, -1}), _names({"Armen", "Guitton" ,"Scify"}), _cost({500000, 500000, 500000})
{
}

short Personalities::get_owner(short const & personality) const
{
	return _owners[personality];
}

int Personalities::get_cost(short const & personality) const
{
	return _cost[personality];
}

void Personalities::set_owner(short const & personality, short p_id)
{
	_owners[personality] = p_id;
}