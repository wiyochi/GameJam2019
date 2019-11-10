#include "Game.hpp"

Game::Game(uint16_t max_turn, ushort nb_players):
	_state(START_TURN),
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

void Game::dice()
{
	_dice_value = rand() % MAX_DICE;
	if(_personalities.get_owner(Personalities::SCIFY) == _nb_turn % 2)
		_state = WAIT_CFY;
	else 
	{
		_state = WAIT_EVENTS;
		_players[_nb_turn % 2].move(_dice_value);
	}
}

void Game::cfy(int c)
{
	if (c == 1)
		_dice_value++;
	else if (c == 2)
		_dice_value--;

	_state = WAIT_EVENTS;
	_players[_nb_turn % 2].move(_dice_value);
}

void Game::buy(short person)
{
	if (_personalities.get_cost(person) <= _players[_nb_turn % 2].get_money())
	{
		_personalities.set_owner(person, _nb_turn % 2);
		_players[_nb_turn % 2].set_money(_players[_nb_turn % 2].get_money() - _personalities.get_cost(person));
	}
}

void Game::events(ushort event)
{
	constexpr int costs[] = {1000, 2000, 5000};

	if (_players[_nb_turn%2].get_money() >= costs[event])
	{
		_players[_nb_turn%2].set_money(_players[_nb_turn%2].get_money() - costs[event]);
	
		
		unsigned int nb_g = _cases_logic[_players[_nb_turn % 2].get_pos() % 20].get_member_glob();
		unsigned int nb_f = _cases_logic[_players[_nb_turn % 2].get_pos() % 20].get_member_flat();
		
		unsigned int mv; // Personne changée
		if (_nb_turn % 2 == 0) // Globiste
		{
			mv = 0.1 * nb_g;
			nb_g+=mv; // TODO : rand 
			nb_f-=mv; // TODO : ajouter des mins
		} else 
		{
			mv = 0.1 * nb_f;
			nb_f+=mv; // TODO : rand 
			nb_g-=mv; // TODO : ajouter des mins
		}

		_cases_logic[_players[_nb_turn % 2].get_pos() % 20].set_member_glob(nb_g);
		_cases_logic[_players[_nb_turn % 2].get_pos() % 20].set_member_flat(nb_f);
	}
}

void Game::end()
{
	if (_nb_turn % 2 == 1) // Les deux joueurs ont joués
		end_of_turn();
	_state = START_TURN;
	_nb_turn++;
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

Player& Game::get_current_player()
{
	return _players[_nb_turn % _players.size()];
}

void Game::do_personalities(ushort const & player, short const & personality)
{
	if (_personalities.get_cost(personality) <= _players[player].get_money())
		_players[player].set_money(_personalities.get_cost(personality));
}

void Game::do_events(ushort const &, ushort const &){}

ushort Game::get_dice() const
{
	return _dice_value;
}