#include "Board.hpp"

Board::Board(sf::Vector2f pos):
    _dice_button(new Button(L"Lancer les dés", sf::Vector2f(900, 100), sf::Vector2f(200, 40))),
	_dice_p_button(new Button(L"Augmenter", sf::Vector2f(900, 150), sf::Vector2f(200, 40))),
	_dice_m_button(new Button(L"Réduire", sf::Vector2f(900, 200), sf::Vector2f(200, 40))),
	_dice_e_button(new Button(L"Conserver", sf::Vector2f(900, 250), sf::Vector2f(200, 40))),
	_buy_cfy_button(new Button(L"Corrompre Cfy", sf::Vector2f(900, 300), sf::Vector2f(200, 40))),
	_buy_guitton_button(new Button(L"Corrompre Guitton", sf::Vector2f(900, 350), sf::Vector2f(200, 40))),
	_buy_armen_button(new Button(L"Corrompre Armen", sf::Vector2f(900, 400), sf::Vector2f(200, 40))),
	_event_1_button(new Button(L"Organiser un meeting", sf::Vector2f(900, 450), sf::Vector2f(200, 40))),
	_event_2_button(new Button(L"Organiser une conférence", sf::Vector2f(900, 500), sf::Vector2f(200, 40))),
	_event_spe_button(new Button(L"Organiser l'évènement spécial", sf::Vector2f(900, 550), sf::Vector2f(200, 40)))
{
    _dice_p_button->set_active(false);
    _dice_m_button->set_active(false);
    _dice_e_button->set_active(false);
    _buy_cfy_button->set_active(false);
    _buy_guitton_button->set_active(false);
    _buy_armen_button->set_active(false);
    _event_1_button->set_active(false);
    _event_2_button->set_active(false);
    _event_spe_button->set_active(false);

    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    sf::Vector2f cases_size(CASES_X[1] - CASES_X[0], CASES_Y[NB_CASES - 1] - CASES_Y[0]);

    _rect.setSize(sf::Vector2f(cases_size.x * (NB_CASES / 4 + 1), cases_size.y * (NB_CASES / 4 + 1)));

    // Cases creation
    for (size_t i = 0; i < NB_CASES; i++)
    {
        switch (CASES_TYPES[i])
        {
        case Case::Chance:
            _cases[i] = new Chance(sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        case Case::Taxes:
            _cases[i] = new Taxes(sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        default:
            _cases[i] = new Case(std::wstring(CASES_NAMES[i]), CASES_TYPES[i], sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size);
            break;
        }
    }

    _view = new View(sf::Vector2f(pos.x + cases_size.x + 10, pos.y + cases_size.y + 10), sf::Vector2f(cases_size.x * (NB_CASES / 4 - 1) - 20, cases_size.y * (NB_CASES / 4 - 1) - 20));
}

Board::~Board()
{
    // probleme a regle
    //std::for_each(_cases.begin(), _cases.end(), [](Case** c){ if (*c) delete *c; });
    // for (auto i = _cases.begin(); i != _cases.end(); i++)
    // {
    //     delete *i;
    // }
    delete _dice_button;
    delete _view;
}

void Board::update(sf::Window& window)
{
    // Case updates
    std::for_each(_cases.begin(), _cases.end(), [&](Case* c){ c->update(window); });

    // Check for new view
    for(auto c = _cases.begin(); c != _cases.end(); c++)
    {
        if((*c)->get_viewed())
        {
            (*c)->set_viewed(false);
            _view->set_case(*c);
            std::wcout << L"Nouveau viewed: " << _view->get_case()->get_name() << std::endl;
        }
    }

    _dice_button->update(window);
	_dice_p_button->update(window);
	_dice_m_button->update(window);
	_dice_e_button->update(window);
	_buy_cfy_button->update(window);
	_buy_guitton_button->update(window);
	_buy_armen_button->update(window);
	_event_1_button->update(window);
	_event_2_button->update(window);
	_event_spe_button->update(window);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    std::for_each(_cases.begin(), _cases.end(), [&](Case* c){ target.draw(*c, states); });
    target.draw(*_view, states);
    target.draw(*_dice_button, states);
	target.draw(*_dice_p_button, states);
	target.draw(*_dice_m_button, states);
	target.draw(*_dice_e_button, states);
	target.draw(*_buy_cfy_button, states);
	target.draw(*_buy_guitton_button, states);
	target.draw(*_buy_armen_button, states);
	target.draw(*_event_1_button, states);
	target.draw(*_event_2_button, states);
	target.draw(*_event_spe_button, states);
}