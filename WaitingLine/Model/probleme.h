#ifndef PROBLEME_H
#define PROBLEME_H
#include "Model/donnee.h"

class Probleme
{
private:
    Donnee donnee;
    int nb_moyen_client; /* nombre moyen de clients suivant par unité de temps */
    int service_temps_moyen; /* service|unité de temps en moyenne */

public:
    Probleme();
    Probleme(Donnee donnee);
    ~Probleme();

    Donnee getDonnee() const;
    void setDonnee(const Donnee &value);
    int getNb_moyen_client() const;
    void setNb_moyen_client(int value);
    int getService_temps_moyen() const;
    void setService_temps_moyen(int value);


};

#endif // PROBLEME_H
