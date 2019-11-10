#include "Personalities.hpp"

Personalities::Personalities():
	_names({"Armen", "Guitton" ,"Scify"}), _cost({500000, 500000, 500000})
{
	_owners[0] = -1;
	_owners[1] = -1;
	_owners[2] = -1;
	
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