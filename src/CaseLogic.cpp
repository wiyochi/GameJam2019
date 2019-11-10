#include "CaseLogic.hpp"

CaseLogic::CaseLogic():
    _member_flat(1000000),
    _member_glob(1000000)
{
}

void CaseLogic::set_member_flat(unsigned int nb)
{
    _member_flat = nb;
}

void CaseLogic::set_member_glob(unsigned int nb)
{
    _member_glob = nb;
}

unsigned int CaseLogic::get_member_flat() const
{
    return _member_flat;
}

unsigned int CaseLogic::get_member_glob() const
{
    return _member_glob;
}