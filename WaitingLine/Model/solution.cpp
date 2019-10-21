#include "solution.h"

double Solution::getValeur_L() const
{
    return valeur_L;
}

void Solution::setValeur_L(double value)
{
    valeur_L = value;
}

double Solution::getValeur_Lq() const
{
    return valeur_Lq;
}

void Solution::setValeur_Lq(double value)
{
    valeur_Lq = value;
}

double Solution::getValeur_W() const
{
    return valeur_W;
}

void Solution::setValeur_W(double value)
{
    valeur_W = value;
}

double Solution::getValeur_Wq() const
{
    return valeur_Wq;
}

void Solution::setValeur_Wq(double value)
{
    valeur_Wq = value;
}

Probleme Solution::getProbleme() const
{
    return probleme;
}

void Solution::setProbleme(const Probleme &value)
{
    probleme = value;
}

Solution::Solution()
{
    
}
