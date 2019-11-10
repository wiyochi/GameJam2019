#ifndef CASELOGIC_HPP_
#define CASELOGIC_HPP_

#include <iostream>
#include <string>
#include <vector>

class CaseLogic
{
private:
    unsigned int _member_flat;
    unsigned int _member_glob;
public:
	CaseLogic();

    void set_member_flat(unsigned int nb);
    void set_member_glob(unsigned int nb);
    unsigned int get_member_flat() const;
    unsigned int get_member_glob() const;
};

#endif
