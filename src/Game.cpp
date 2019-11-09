#include "Game.hpp"

Game::Game(uint16_t max_turn, ushort nb_players):
	_max_turn(max_turn)
{
	for (ushort i = 0; i < nb_players; i++)
	{
		std::string name;
		std::cin >> name;
		_players.push_back(Player(name));
	}
	std::getchar();
	
}

void Game::run()
{
	for (_nb_turn = 0; _nb_turn < _max_turn; _nb_turn++)
	{
		std::cout << "Tour n°" << _nb_turn << std::endl;
		turn();
	}
}

void Game::turn()
{
	for (ushort i = 0; i < _players.size(); i++)
	{
		std::cout << "\tAu tour du joueur : " << _players[i].get_name() << " (" << i << ')' << std::endl;
		ushort dice_value = rand() % MAX_DICE;
		ushort event;
		short personalities;
		_players[i].play(dice_value, event, personalities);
		do_events(i, event);
		do_personalities(i, personalities);
	}
}

void Game::do_events(ushort const & player, ushort const & event)
{

}

void Game::do_personalities(ushort const & player, short const & personality)
{
	if (_personalities.get_cost(personality) <= _players[player].get_money())
		_players[player].set_money(_personalities.get_cost(personality));
}
