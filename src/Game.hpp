#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "Personalities.hpp"

class Game
{
private:
	static constexpr ushort MAX_DICE = 8;
	static constexpr int MONEY = 30000;
	Personalities _personalities;
	// Ajouter plateau
	std::vector<Player> _players;	// Liste des joueurs
	const uint16_t _max_turn; 		// Nombre total de tour dans la partie
	int _nb_turn;					// Nombre de tour actuellement joué

	void do_events(ushort const & player, ushort const & event);
	void do_personalities(ushort const & player, short const & personalities);
public:
	Game(uint16_t max_turn, ushort nb_joueur);
	void end_of_turn();
	void turn(); 					// Execute toute la partie (tous les tours)
	void run();						// Fais jouer chaque joueur à son tour
};

#endif
