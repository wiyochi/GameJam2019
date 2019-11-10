#include "Game.hpp"

Game::Game(uint16_t max_turn, short nb_players):
	_state(START_TURN),
	_personalities(),
	_max_turn(max_turn),
	gen(rd()),
	dis_dice(1, MAX_DICE),
	dis_meeting(40000, 60000),
	dis_conference(80000, 100000),
	dis_special(300000, 350000)
{
	_personalities.set_owner(Personalities::ARMEN, -1);
	_personalities.set_owner(Personalities::GUITTON, -1);
	_personalities.set_owner(Personalities::SCIFY, -1);

	for (short i = 0; i < nb_players; i++)
	{
		std::ostringstream oss;
		oss << "Player " << i + 1;
		std::string name = oss.str();
		_players.push_back(Player(name));
	}
	_players.push_back(Player("Globistes"));
	_players.push_back(Player("Platistes"));
	//std::getchar();
	
}

void Game::dice()
{
	_dice_value = dis_dice(gen);
	if(_personalities.get_owner(Personalities::SCIFY) == _nb_turn % 2)
		_state = WAIT_CFY;
	else 
	{
		_state = WAIT_EVENTS;
		_players[_nb_turn % 2].move_m(_dice_value);
	}
}

void Game::cfy(int c)
{
	if (c == 1)
		_dice_value++;
	else if (c == 2)
		_dice_value--;

	_state = WAIT_EVENTS;
	_players[_nb_turn % 2].move_m(_dice_value);
}

void Game::buy(short person)
{
	if (_personalities.get_cost(person) <= _players[_nb_turn % 2].get_money())
	{
		_personalities.set_owner(person, _nb_turn % 2);
		_players[_nb_turn % 2].set_money(_players[_nb_turn % 2].get_money() - _personalities.get_cost(person));
	}
}

void Game::events(short event)
{
	constexpr int costs[] = {1000, 2000, 5000};

	if (_players[_nb_turn%2].get_money() >= costs[event])
	{
		_players[_nb_turn%2].set_money(_players[_nb_turn%2].get_money() - costs[event]);
	
		
		unsigned int nb_g = _cases_logic[_players[_nb_turn % 2].get_pos() % 20].get_member_glob();
		unsigned int nb_f = _cases_logic[_players[_nb_turn % 2].get_pos() % 20].get_member_flat();

		int nb_rand = 0;
		if (event == 1)
			nb_rand = dis_meeting(gen);
		else if (event == 2)
			nb_rand = dis_conference(gen);
		else
			nb_rand = dis_special(gen);

		if (_nb_turn % 2 == 0) // Globiste
		{
			if ((int)nb_f - nb_rand > 0)
			{
				nb_g += nb_rand;
				nb_f -= nb_rand;
			}
			else
			{
				nb_g += nb_f;
				nb_f = 0;
			}
		} else 
		{
			if ((int)nb_g - nb_rand > 0)
			{
				nb_f += nb_rand;
				nb_g -= nb_rand;
			}
			else
			{
				nb_f += nb_g;
				nb_g = 0;
			}
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
		short event;
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

void Game::do_personalities(short const & player, short const & personality)
{
	if (_personalities.get_cost(personality) <= _players[player].get_money())
		_players[player].set_money(_personalities.get_cost(personality));
}

void Game::do_events(short const &, short const &){}

ushort Game::get_dice() const
{
	return _dice_value;
}