#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>

enum team{FLAT, ROUND};														// Equipes du jeu
constexpr ushort nb_cases = 20;

class Player
{
private:
	std::string _name;														// Nom du joueur
	team _team;																// Equipe à laquelle il appartient
	ushort _pos;															// Position du joueur sur le plateau
	uint _money;															// Money money money #ramenez le flouzz

	void move(ushort dice_value, bool have_scify);											// Déplacement du joueur
	ushort do_board_action();												// Faire les actions par rapport à la case
	short do_personalities_action(); 										// Possibilité d'acheter des personnalitées.
public:
	Player(std::string name);												// Création d'un nouveau joueur
	std::string const & get_name() const;									// Renvoie le nom du joueur
	int get_money() const;													// Récupération du flouzz du joueur
	void set_money(uint money);												// Changement de l'argent du joueur
	void play(ushort dice_value, bool have_scify, ushort & event, short & personalities);	// Ensemble du tour du joueur
	ushort get_pos() const;
};

#endif