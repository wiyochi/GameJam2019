#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>

enum team{FLAT, ROUND};														// Equipes du jeu
constexpr short nb_cases = 20;

class Player
{
private:
	std::string _name;														// Nom du joueur
	team _team;																// Equipe à laquelle il appartient
	short _pos;															// Position du joueur sur le plateau
	uint _money;															// Money money money #ramenez le flouzz

	void move(uint16_t dice_value, bool have_scify);											// Déplacement du joueur
	short do_board_action();												// Faire les actions par rapport à la case
	short do_personalities_action(); 										// Possibilité d'acheter des personnalitées.
public:
	int _nb_pays;

	Player(std::string name);												// Création d'un nouveau joueur
	std::string const & get_name() const;									// Renvoie le nom du joueur
	int get_money() const;													// Récupération du flouzz du joueur
	void set_money(uint money);												// Changement de l'argent du joueur
	void play(short dice_value, bool have_scify, short & event, short & personalities);	// Ensemble du tour du joueur
	short get_pos() const;
	void move_m(short);
};

#endif