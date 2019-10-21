#ifndef SOLUTION_H
#define SOLUTION_H
#include "Model/probleme.h"

class Solution
{
private:
    double valeur_L; /* nombre moyen de clients dans le systeme */
    double valeur_Lq; /* nombre moyen de clients dans la file */
    double valeur_W; /* duree moyenne d'attente dans le systeme */
    double valeur_Wq; /* duree moyenne d'attente dans la file */
    Probleme probleme;

public:
    Solution();
    Solution(Probleme prob);
    ~Solution();

    double getValeur_L() const;
    void setValeur_L(double value);
    double getValeur_Lq() const;
    void setValeur_Lq(double value);
    double getValeur_W() const;
    void setValeur_W(double value);
    double getValeur_Wq() const;
    void setValeur_Wq(double value);
    Probleme getProbleme() const;
    void setProbleme(const Probleme &value);

    void calculerValeur_L();
    void calculerValeur_Lq();
    void calculerValeur_W();
    void calculerValeur_Wq();


};

#endif // SOLUTION_H
