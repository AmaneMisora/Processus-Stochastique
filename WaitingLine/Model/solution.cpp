#include "solution.h"
/**
 * @brief Getter : L
*/
double Solution::getValeur_L() const
{
    return valeur_L;
}

/**
 * @brief Setter : L
*/
void Solution::setValeur_L(double value)
{
    valeur_L = value;
}

/**
 * @brief Getter : Lq
*/
double Solution::getValeur_Lq() const
{
    return valeur_Lq;
}

/**
 * @brief Setter : Lq
*/
void Solution::setValeur_Lq(double value)
{
    valeur_Lq = value;
}

/**
 * @brief Getter : W
*/
double Solution::getValeur_W() const
{
    return valeur_W;
}

/**
 * @brief Setter : W
*/
void Solution::setValeur_W(double value)
{
    valeur_W = value;
}

/**
 * @brief Getter : Wq
*/
double Solution::getValeur_Wq() const
{
    return valeur_Wq;
}

/**
 * @brief Setter : Wq
*/
void Solution::setValeur_Wq(double value)
{
    valeur_Wq = value;
}

/**
 * @brief Getter : Probleme
*/
Probleme Solution::getProbleme() const
{
    return probleme;
}

/**
 * @brief Setter : Probleme
*/
void Solution::setProbleme(const Probleme &value)
{
    probleme = value;
}

/**
 * @brief Constructeur par défaut
 */
Solution::Solution()
{
    
}

/**
 * @brief Constructeur par analyser la probleme
 * @param donnee
 */
Solution::Solution(Probleme prob)
{

}

/**
 * @brief calculer Valeur_L
 */
void Solution::calculerValeur_L()
{

}

/**
 * @brief calculer Valeur_Lq
 */
void Solution::calculerValeur_Lq()
{

}

/**
 * @brief calculer Valeur_W
 */
void Solution::calculerValeur_W()
{

}

/**
 * @brief calculer Valeur_Wq
 */
void Solution::calculerValeur_Wq()
{

}
