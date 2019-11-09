#include "Personalities.hpp"

Personalities::Personalities():
	_names({"Armen", "Guitton" ,"Scify"}), _owners({-1, -1, -1}), _cost({500000, 500000, 500000})
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