#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"


class Game
{
private:
	static constexpr ushort MAX_DICE = 8;
	// Ajouter plateau
	std::vector<Player> _players;	// Liste des joueurs
	const uint16_t _max_turn; 		// Nombre total de tour dans la partie
	int _nb_turn;					// Nombre de tour actuellement joué

	void do_events(ushort const & player, ushort const & event);
public:
	Game(uint16_t max_turn, ushort nb_joueur);
	void turn(); 					// Execute toute la partie (tous les tours)
	void run();						// Fais jouer chaque joueur à son tour
};

#endif
