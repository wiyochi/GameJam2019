#ifndef PAYS_H_
#define PAYS_H_

#include "Case.hpp"
#include "../../CaseLogic.hpp"

class Pays : public Case
{
public:
    Pays(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size, CaseLogic * case_logic);
    ~Pays();


private:
};

#endif