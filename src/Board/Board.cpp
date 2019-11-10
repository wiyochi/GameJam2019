#include "Board.hpp"

Board::Board(sf::Vector2f pos):
    _g(Game(10, 2)),
    _dice_button(new Button(L"Lancer les dés", sf::Vector2f(1000, 50), sf::Vector2f(200, 40))),
	_dice_p_button(new Button(L"Augmenter", sf::Vector2f(1000, 50), sf::Vector2f(200, 40))),
	_dice_m_button(new Button(L"Réduire", sf::Vector2f(1000, 100), sf::Vector2f(200, 40))),
	_dice_e_button(new Button(L"Conserver", sf::Vector2f(1000, 150), sf::Vector2f(200, 40))),
	_buy_cfy_button(new Button(L"Corrompre Cfy", sf::Vector2f(1000, 100), sf::Vector2f(200, 40))),
	_buy_guitton_button(new Button(L"Corrompre Guitton", sf::Vector2f(1000, 150), sf::Vector2f(200, 40))),
	_buy_armen_button(new Button(L"Corrompre Armen", sf::Vector2f(1000, 200), sf::Vector2f(200, 40))),
	_buy_skip_button(new Button(L"Skip Perso", sf::Vector2f(1000, 50), sf::Vector2f(200, 40))),
  	_event_1_button(new Button(L"Organiser un meeting", sf::Vector2f(1000, 100), sf::Vector2f(200, 40))),
	_event_2_button(new Button(L"Organiser une conférence", sf::Vector2f(1000, 150), sf::Vector2f(200, 40))),
	_event_spe_button(new Button(L"Organiser l'évènement spécial", sf::Vector2f(1000, 200), sf::Vector2f(200, 40))),
    _event_skip_button(new Button(L"Skip évènement", sf::Vector2f(1000, 50), sf::Vector2f(200, 40))),
    _tout(sf::Vector2f(1920, 1080)),
    _code(0)
{
    /*
    _dice_p_button->set_active(false);
    _dice_m_button->set_active(false);
    _dice_e_button->set_active(false);
    _buy_cfy_button->set_active(false);
    _buy_guitton_button->set_active(false);
    _buy_armen_button->set_active(false);
    _event_1_button->set_active(false);
    _event_2_button->set_active(false);
    _event_spe_button->set_active(false);
*/
    if (_font.loadFromFile(FONT_PATH))
	{
		_text_turn.setFont(_font);
		_text_turn.setFillColor(sf::Color::White);
		_text_turn.setStyle(sf::Text::Bold);
		_text_turn.setCharacterSize(15);
        _text_turn.setPosition(sf::Vector2f(1000.f, 0.f));
	}
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    sf::Vector2f cases_size(100.f, 150.f);

    _rect.setSize(sf::Vector2f(cases_size.x * (NB_CASES / 4) + 2 * cases_size.y, cases_size.x * (NB_CASES / 4) + 2 * cases_size.y));

    unsigned int div = NB_CASES / 4;
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
            _cases[i] = new Pays(std::wstring(CASES_NAMES[i]), CASES_TYPES[i], sf::Vector2f(pos.x + CASES_X[i], pos.y + CASES_Y[i]), cases_size, &_g._cases_logic[i]);
            break;
        }
        if (i < div)
            ;
        else if (i < div * 2)
            _cases[i]->rotate(90.f);
        else if (i < div * 3)
            _cases[i]->rotate(180.f);
        else if (i < div * 4)
            _cases[i]->rotate(-90.f);
    }

    _view = new View(sf::Vector2f(pos.x + cases_size.y + 10, pos.y + cases_size.y + 10), sf::Vector2f(cases_size.x * (NB_CASES / 4) - 20, cases_size.x * (NB_CASES / 4) - 20));

    constexpr char FONT_NOD_PATH[] = "resources/fonts/Roboto-Thin.ttf";
    sf::Font * font = new sf::Font();
    (*font).loadFromFile(FONT_NOD_PATH);

    _text_code = sf::Text("Code", *font, 20);
    _text_code.setPosition(700, 100);

    _pion[0].setRadius(10);
    _pion[0].setFillColor(sf::Color::Red);
    _pion[0].setPosition(_cases[0]->get_position());
    _pion[1].setRadius(10);
    _pion[1].setFillColor(sf::Color::Blue);
    _pion[1].setPosition(_cases[0]->get_position());


    _img.loadFromFile("resources/textures/book.png");
    _tout.setTexture(&_img);

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
    // Code d'updates

    switch(_g._state)
    {
        case Game::START_TURN:
            _dice_button->set_active(true);
            _dice_p_button->set_active(true);
            _dice_p_button->set_active(false);
            _dice_m_button->set_active(false);
            _dice_e_button->set_active(false);
            _buy_cfy_button->set_active(false);
            _buy_guitton_button->set_active(false);
            _buy_armen_button->set_active(false);
            _event_1_button->set_active(false);
            _event_2_button->set_active(false);
            _event_spe_button->set_active(false);
            _buy_skip_button->set_active(false);
            _event_skip_button->set_active(false);
            _code = 1;
            break;
        case Game::WAIT_CFY:
            _dice_button->set_active(false);
            _dice_p_button->set_active(false);
            _dice_p_button->set_active(true);
            _dice_m_button->set_active(true);
            _dice_e_button->set_active(true);
            _buy_cfy_button->set_active(false);
            _buy_guitton_button->set_active(false);
            _buy_armen_button->set_active(false);
            _event_1_button->set_active(false);
            _event_2_button->set_active(false);
            _event_spe_button->set_active(false);
            _buy_skip_button->set_active(false);
            _event_skip_button->set_active(false);
            break;
        case Game::WAIT_EVENTS:
            _dice_button->set_active(false);
            _dice_p_button->set_active(false);
            _dice_p_button->set_active(false);
            _dice_m_button->set_active(false);
            _dice_e_button->set_active(false);
            _buy_cfy_button->set_active(false);
            _buy_guitton_button->set_active(false);
            _buy_armen_button->set_active(false);
            _buy_skip_button->set_active(false);
            _event_1_button->set_active(true);
            _event_2_button->set_active(true);
            _event_spe_button->set_active(true);
            _event_skip_button->set_active(true);
            break;
        case Game::WAIT_PERSO:
            _dice_button->set_active(false);
            _dice_p_button->set_active(false);
            _dice_p_button->set_active(false);
            _dice_m_button->set_active(false);
            _dice_e_button->set_active(false);
            _buy_cfy_button->set_active(true);
            _buy_guitton_button->set_active(true);
            _buy_armen_button->set_active(true);
            _buy_skip_button->set_active(true);
            _event_1_button->set_active(false);
            _event_2_button->set_active(false);
            _event_spe_button->set_active(false);
            _event_skip_button->set_active(false);
            break;
    }



    // Case updates
    std::for_each(_cases.begin(), _cases.end(), [&](Case* c){ c->update(window); });

    // Check for new view
    for(auto c = _cases.begin(); c != _cases.end(); c++)
    {
        if((*c)->get_viewed())
        {
            (*c)->set_viewed(false);
            _view->set_case(*c);
        }
    }

    _dice_button->update(window);
	_dice_p_button->update(window);
	_dice_m_button->update(window);
	_dice_e_button->update(window);
	_buy_cfy_button->update(window);
	_buy_guitton_button->update(window);
	_buy_armen_button->update(window);
    _buy_skip_button->update(window);
	_event_1_button->update(window);
	_event_2_button->update(window);
	_event_spe_button->update(window);
    _event_skip_button->update(window);

    if(_dice_button->is_clicked())
        _g.dice();
	else if(_dice_p_button->is_clicked())
        _g.cfy(1);
	else if(_dice_m_button->is_clicked())
        _g.cfy(2);
	else if(_dice_e_button->is_clicked())
        _g.cfy(0);
	else if(_buy_cfy_button->is_clicked())
        _g.buy(Personalities::SCIFY);
	else if(_buy_guitton_button->is_clicked())
        _g.buy(Personalities::GUITTON);
	else if(_buy_armen_button->is_clicked())
        _g.buy(Personalities::ARMEN);
    else if(_buy_skip_button->is_clicked())
        _g.end();
	else if(_event_1_button->is_clicked())
        _g.events(1);
	else if(_event_2_button->is_clicked())
        _g.events(2);
	else if(_event_spe_button->is_clicked())
        _g.events(3);
    else if(_event_skip_button->is_clicked())
        _g._state = Game::WAIT_PERSO;

    std::ostringstream oss;
    oss << "Personnalities : \n" << _g._personalities.get_owner(0)
    << "\n - " << _g._personalities.get_owner(0)
    << "\n - " << _g._personalities.get_owner(0);
    _text_code.setString(oss.str());

    _text_turn.setString(_g.get_current_player().get_name());

    _pion[_g._nb_turn % 2].setPosition(_cases[_g.get_current_player().get_pos()]->get_position());
}

int & Board::get_code()
{
    return _code;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_tout, states);
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
    target.draw(*_buy_skip_button, states);
	target.draw(*_event_1_button, states);
	target.draw(*_event_2_button, states);
	target.draw(*_event_spe_button, states);
    target.draw(*_event_skip_button, states);

    target.draw(_text_code, states);
    target.draw(_text_turn, states);

    target.draw(_pion[0], states);
    target.draw(_pion[1], states);
}