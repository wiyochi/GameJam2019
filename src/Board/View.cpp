#include "View.hpp"

View::View(sf::Vector2f const & pos, sf::Vector2f const & size) :
    _pos(pos),
    _size(size),
    _rect(size)
{
    _rect.setPosition(pos);
    _rect.setOutlineThickness(1);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Transparent);

    if (_font.loadFromFile(FONT_PATH))
	{
		_text_title.setFont(_font);
		_text_title.setFillColor(sf::Color::White);
		_text_title.setStyle(sf::Text::Bold);
		_text_title.setCharacterSize(15);
        _text_title.setPosition(pos);

        _text_center.setFont(_font);
		_text_center.setFillColor(sf::Color::White);
		_text_center.setStyle(sf::Text::Bold);
		_text_center.setCharacterSize(15);
        _text_center.setPosition(pos);
	}
}

View::~View()
{
}

void View::set_case(Case* c)
{
    std::ostringstream oss;
    _case = c;

    _text_title.setString(c->get_name());
    sf::Rect title_size = _text_title.getGlobalBounds();
    _text_title.setPosition(sf::Vector2f(_pos.x + _size.x / 2 - title_size.width / 2, _pos.y));

    switch (_case->get_type())
    {
    case Case::Chance:
        _text_center.setString(L"Carte chance !");
        break;
    case Case::Taxes:
        _text_center.setString(L"C'est la carotte");
        break;
    default:
        if (Pays * p = dynamic_cast<Pays*>(_case))
        {
            oss << "Adhérent à Terre Plate: ";
            oss << p->get_member_flat() << std::endl;
            oss << "Adhérent à Terre Ronde: ";
            oss << p->get_member_glob() << std::endl;
            _text_center.setString(oss.str());
        }
        break;
    }

    sf::Rect center_size = _text_center.getGlobalBounds();
    _text_center.setPosition(sf::Vector2f(_pos.x + _size.x / 2 - center_size.width / 2, _pos.y + _size.y / 2 - center_size.height / 2));
}

Case* View::get_case()
{
    return _case;
}

void View::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_rect, states);
    target.draw(_text_title, states);
    target.draw(_text_center, states);
}