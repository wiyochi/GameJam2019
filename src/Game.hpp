#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>

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
	int _nb_turn;					// Nombre de tour actuellement joué

	Game(uint16_t max_turn, short nb_joueur);
	void end_of_turn();
	void turn(); 					// Execute toute la partie (tous les tours)
	void run();						// Fais jouer chaque joueur à son tour
	void dice();
	void cfy(int i);
	void buy(short person);
	void events(short event);
	void end();
	Player& get_current_player();
	std::array<CaseLogic, 20> _cases_logic;
	std::vector<Player> _players;	// Liste des joueurs
	ushort get_dice() const;


private:
	static constexpr short MAX_DICE = 8;
	static constexpr int MONEY = 30000;
	// Ajouter plateau
	const uint16_t _max_turn; 		// Nombre total de tour dans la partie
	short _dice_value;
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis_dice;
	std::uniform_int_distribution<int> dis_meeting;
	std::uniform_int_distribution<int> dis_conference;
	std::uniform_int_distribution<int> dis_special;

	void do_events(short const & player, short const & event);
	void do_personalities(short const & player, short const & personalities);
};

#endif
