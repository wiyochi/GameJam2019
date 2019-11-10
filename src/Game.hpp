#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "CaseLogic.hpp"
#include "Personalities.hpp"

class Game
{
public:
	enum GameState {
		START_TURN, 	// Attente des dès.
		WAIT_CFY, 		// Attente de la réponse de Cfy.
		WAIT_EVENTS,	// Attente des events.
		WAIT_PERSO	// Attente de l'achat des personnalités.
	};

	GameState _state;
	Personalities _personalities;

	Game(uint16_t max_turn, ushort nb_joueur);
	void end_of_turn();
	void turn(); 					// Execute toute la partie (tous les tours)
	void run();						// Fais jouer chaque joueur à son tour
	void dice();
	void cfy(int i);
	void buy(short person);
	void events(ushort event);
	void end();
	std::array<CaseLogic, 20> _cases_logic;


private:
	static constexpr ushort MAX_DICE = 8;
	static constexpr int MONEY = 30000;
	// Ajouter plateau
	std::vector<Player> _players;	// Liste des joueurs
	const uint16_t _max_turn; 		// Nombre total de tour dans la partie
	int _nb_turn;					// Nombre de tour actuellement joué
	ushort _dice_value;

	void do_events(ushort const & player, ushort const & event);
	void do_personalities(ushort const & player, short const & personalities);
};

#endif
