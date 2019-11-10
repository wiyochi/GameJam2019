#ifndef PERSONALITIES_HPP_
#define PERSONALITIES_HPP_

#include <iostream>
#include <string>
#include <array>

class Personalities
{
private:
	std::array<short, 3> _owners; 		// A qui appartient une personnalité
	std::array<std::string, 3> _names;	// Nom des personnalités : Useless ?
	std::array<int, 3> _cost;			// Cout d'achat de chaque personnalité
public:
	static constexpr short ARMEN = 1;
	static constexpr short GUITTON = 1;
	static constexpr short SCIFY = 1;

	Personalities();
	short get_owner(short const & personality) const;	// Permet de savoir à qui appartient une personnalitée
	int get_cost(short const & personality) const;		// Récupération du coût de rachat d'une personnalitée
	void set_owner(short const & personality, short p_id);
};

#endif
