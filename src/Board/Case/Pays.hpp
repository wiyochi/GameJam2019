#ifndef PAYS_H_
#define PAYS_H_

#include "Case.hpp"

class Pays : public Case
{
public:
    Pays(std::wstring const & name, Type type, sf::Vector2f const & pos, sf::Vector2f const & size);
    ~Pays();

    void set_member_flat(unsigned int nb);
    void set_member_glob(unsigned int nb);
    unsigned int get_member_flat() const;
    unsigned int get_member_glob() const;

private:
    unsigned int _member_flat;
    unsigned int _member_glob;
};

#endif