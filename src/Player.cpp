#include "Player.hpp"

Player::Player(std::string name):
	_name(name), _pos(0), _money(1000000000)
{
}

int Player::get_money() const
{
	return _money;
}

void Player::set_money(uint money)
{
	_money = money;
}

std::string const & Player::get_name() const
{
	return _name;
}


void Player::play(ushort dice_value, bool have_sciphy, ushort & event, short & personalities)
{
	std::getchar();

	
	move(dice_value, have_sciphy);
	event = do_board_action();
	personalities = do_personalities_action();
}

void Player::move(uint16_t dice_value, bool have_sciphy)
{
	std::cout << "\tJ'ai fait un " << dice_value << '.' << std::endl;

	if (have_sciphy)
	{
		before3:
		std::cout << "\tVous disposez du bonus siphy, vous pouvez modifiez de un le résultat du dé." << std::endl;
		std::cout << "\t\t1) Garder le résultat" << std::endl;
		std::cout << "\t\t2) Augmenter le résultat" << std::endl;
		std::cout << "\t\t3) Diminuer le résultat" << std::endl;

		int choice;
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				break;
			case 2:
				std::cout << "\tVous avez décidé d'augmenter de 1." << std::endl;
				dice_value++;
				break;
			case 3:
				std::cout << "\tVous avez décidé de diminuer de 1." << std::endl;
				dice_value--;
				break;
			default:
				goto before3;
		}
	}

	std::cout << "\tJ'avance de la case " << _pos << " à la case ";
	_pos += dice_value;// Avance du pion
	_pos %= nb_cases; 
	std::cout << _pos << std::endl;
}

ushort Player::do_board_action()
{
	before: // ATTENTION GOTO LABEL
	std::cout << "\tQuel évènement organisé ? :" << std::endl;
	std::cout << "\t\t1 : Rien" << std::endl;
	std::cout << "\t\t2 : Meeting" << std::endl;
	std::cout << "\t\t3 : Conférence" << std::endl;

	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "\tVous décidez de ne rien faire." << std::endl;
		break;
	case 2:
		std::cout << "\tVous décidez d'organiser un meeting." << std::endl;
		break;
	case 3:
		std::cout << "\tVous décidez d'organiser une conférence." << std::endl;
		break;
	default:
		goto before; // ATTENTION GOTO
	} 

	return choice;
}

short Player::do_personalities_action()
{
	before2: // ATTENTION GOTO LABEL
	std::cout << "\tVoulez-vous soudvoyer une personnalitée ? :" << std::endl;
	std::cout << "\t\t-1 : Non" << std::endl;
	std::cout << "\t\t1 : Armen" << std::endl;
	std::cout << "\t\t2 : Guitton" << std::endl;
	std::cout << "\t\t3 : Scify" << std::endl;

	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case -1:
		std::cout << "\tVous décidez de ne rien faire." << std::endl;
		break;
	case 1:
		std::cout << "\tVous décidez de payer Armen" << std::endl;
		break;
	case 2:
		std::cout << "\tVous décidez de payer Guitton." << std::endl;
		break;
	case 3:
		std::cout << "\tVous décidez de payer Scify." << std::endl;
		break;
	default:
		goto before2; // ATTENTION GOTO
	} 
	return choice;
}

ushort Player::get_pos() const
{
	return _pos;
}