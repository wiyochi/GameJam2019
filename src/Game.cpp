#include "Game.hpp"

Game::Game(uint16_t max_turn, ushort nb_players):
	_max_turn(max_turn)
{
	for (ushort i = 0; i < nb_players; i++)
	{
		std::ostringstream oss;
		oss << "Player " << i + 1;
		std::string name = oss.str();
		_players.push_back(Player(name));
	}
	//std::getchar();
	
}
/*
 * Liste des codes :
 * 0 : début de tour
 * 1 : a cliqué sur lancer dés
 * 2 : a cliqué sur plus dés
 * 3 : a cliqué sur moins dés
 * 4 : a cliqué sur garder dés
 * 5 : a cliqué sur payer cfy
 * 6 : a cliqué sur payer guitton
 * 7 : a cliqué sur payer armen
 * 8 : a cliqué sur event 1
 * 9 : a clique sur event 2
 * 10 : a cliqué sur event spé
 * 11 : jeu valide dé et par sur demande de cfy
 * 12 : pas de cfy on passe aux events
 * 13 : on a fini les events
 * 14 : fin de tour
 * 15 : en attente des perso
 * 16 : dés lancés
 */
void Game::update(int & code)
{
	Player & p = _players[_nb_turn % 2];
	switch(code)
	{
		case 1:
			code = 12;
			_dice_value = rand() % MAX_DICE;
			if (_personalities.get_owner(Personalities::SCIFY) == _nb_turn % 2)
				code = 11;
			break;
		case 2:
			_dice_value++;
			code = 12;
			break;
		case 3:
			_dice_value--;
			code = 12;
			break;
		case 4:
			code = 12;
			break;
		case 5:
			if (_personalities.get_cost(Personalities::SCIFY) <= p.get_money())
			{
				p.set_money(p.get_money() - _personalities.get_cost(Personalities::SCIFY));
				//TODO : incrémenter cout & intégrer le temps de protection.
				//     : add set_owner()
			code = 14;
			}
			break;
		case 6:
			if (_personalities.get_cost(Personalities::GUITTON) <= p.get_money())
			{
				p.set_money(p.get_money() - _personalities.get_cost(Personalities::GUITTON));
				//TODO : incrémenter cout & intégrer le temps de protection.
				//     : add set_owner()
			code = 14;
			}
			break;
		case 7:
			if (_personalities.get_cost(Personalities::ARMEN) <= p.get_money())
			{
				p.set_money(p.get_money() - _personalities.get_cost(Personalities::ARMEN));
				//TODO : incrémenter cout & intégrer le temps de protection.
				//     : add set_owner()
			code = 14;
			}
			break;
		case 8:
			// TODO : implémenter la fonctionnalité des events
			code = 15;
			break;
		case 9:
			code = 15;
			break;
		case 10:
			code = 15;
			break;
	}
}

void Game::run()
{
	for (_nb_turn = 0; _nb_turn < _max_turn; _nb_turn++)
	{
		std::cout << "Tour n°" << _nb_turn << std::endl;
		turn();
		end_of_turn();
	}
}

void Game::end_of_turn()
{
	// TODO ajouter les gains de thunes vis à vis des membres de la secte (0.5% des membres)
	for (ushort i = 0; i < _players.size(); i++)
	{
		if(_personalities.get_owner(Personalities::GUITTON) == i)
			_players[i].set_money(_players[i].get_money() + 1.5 * (MONEY));
		else
			_players[i].set_money(_players[i].get_money() + MONEY);
		
	}
}

void Game::turn()
{
	for (ushort i = 0; i < _players.size(); i++)
	{
		std::cout << "\tAu tour du joueur : " << _players[i].get_name() << " (" << i << ')' << std::endl;
		_dice_value = rand() % MAX_DICE;
		ushort event;
		short personalities;
		_players[i].play(_dice_value, _personalities.get_owner(Personalities::SCIFY) == i, event, personalities);
		do_events(i, event);
		do_personalities(i, personalities);
	}
}

void Game::do_events(ushort const &, ushort const &)
{

}

void Game::do_personalities(ushort const & player, short const & personality)
{
	if (_personalities.get_cost(personality) <= _players[player].get_money())
		_players[player].set_money(_personalities.get_cost(personality));
}
