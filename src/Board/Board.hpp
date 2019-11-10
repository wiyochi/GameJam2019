#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Case/Case.hpp"
#include "Case/Pays.hpp"
#include "Case/Taxes.hpp"
#include "Case/Chance.hpp"
#include "View.hpp"
#include "../UI/Button.hpp"

#include "../Game.hpp"

#include <sstream>

extern const char FONT_PATH[];

constexpr unsigned int NB_CASES = 20;
constexpr std::wstring_view  CASES_NAMES[NB_CASES] = {
    L"Le timor\noriental", L"France" , L"Pologne", L"Mongolie", L"Mexique",
    L"US", L"Corée\ndu nord", L"Japon", L"Chance", L"Allemagne",
    L"Australie", L"Paraguay", L"Chance", L"Perou", L"Egypte",
    L"Russie", L"Impots", L"Nouvelle\nZelande", L"Chance", L"Chine"
};
constexpr Case::Type        CASES_TYPES[NB_CASES] = {
    Case::Education, Case::Propaganda, Case::Goulag, Case::Education, Case::Propaganda,
    Case::USA, Case::Goulag, Case::Propaganda, Case::Chance, Case::Live,
    Case::Education, Case::Live, Case::Chance, Case::Propaganda, Case::Education,
    Case::Goulag, Case::Taxes, Case::Live, Case::Chance, Case::Goulag
};

/*
constexpr float             CASES_X[NB_CASES] = {
    0.0f, 100.f, 200.f, 300.f, 400.f, 500.f,
    500.f, 500.f, 500.f, 500.f, 500.f,
    400.f, 300.f, 200.f, 100.f, 0.f,
    0.f, 0.f, 0.f, 0.f
};

constexpr float             CASES_Y[NB_CASES] = {
    0.0f, 0.f, 0.f, 0.f, 0.f, 0.f,
    100.f, 200.f, 300.f, 400.f, 500.f,
    500.f, 500.f, 500.f, 500.f, 500.f,
    400.f, 300.f, 200.f, 100.f
};*/
constexpr float             CASES_X[NB_CASES] = {
    150.0f, 250.f, 350.f, 450.f, 550.f,
    800.f, 800.f, 800.f, 800.f, 800.f,
    650.f, 550.f, 450.f, 350.f, 250.f,
    0.f, 0.f, 0.f, 0.f, 0.f
};

constexpr float             CASES_Y[NB_CASES] = {
    0.0f, 0.f, 0.f, 0.f, 0.f,
    150.f, 250.f, 350.f, 450.f, 550.f,
    800.f, 800.f, 800.f, 800.f, 800.f,
    650.f, 550.f, 450.f, 350.f, 250.f
};

class Board : public sf::Drawable
{
public:
    Board(sf::Vector2f pos);
    ~Board();

    void update(sf::Window& window);
    int & get_code();

private:
    Game _g;
    Button * _dice_button;
	Button * _dice_p_button;
	Button * _dice_m_button;
	Button * _dice_e_button;
	Button * _buy_cfy_button;
	Button * _buy_guitton_button;
	Button * _buy_armen_button;
	Button * _buy_skip_button;
	Button * _event_1_button;
	Button * _event_2_button;
	Button * _event_spe_button;
	Button * _event_skip_button;
    sf::Text _text_code;

    sf::Font                    _font;
    sf::Text                    _text_turn;
    sf::RectangleShape          _rect;
    std::array<Case*, NB_CASES> _cases;
    View*                       _view;
    sf::CircleShape             _pion[2];
    sf::Texture _img;
    sf::RectangleShape _tout;

    int _code;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif