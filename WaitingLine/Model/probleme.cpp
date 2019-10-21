#include "probleme.h"
 /**
  * @brief Getter : Donnee
*/
Donnee Probleme::getDonnee() const
{
    return donnee;
}

/**
 * @brief Setter : Donnee
*/
void Probleme::setDonnee(const Donnee &value)
{
    donnee = value;
}

/**
 * @brief Getter : Nb_moyen_client
*/
int Probleme::getNb_moyen_client() const
{
    return nb_moyen_client;
}

/**
 * @brief Setter : Nb_moyen_client
*/
void Probleme::setNb_moyen_client(int value)
{
    nb_moyen_client = value;
}

/**
 * @brief Getter : Service_temps_moyen
*/
int Probleme::getService_temps_moyen() const
{
    return service_temps_moyen;
}

/**
 * @brief Setter : setService_temps_moyen
*/
void Probleme::setService_temps_moyen(int value)
{
    service_temps_moyen = value;
}

/**
 * @brief Constructeur par défaut
 */
Probleme::Probleme()
{
    
}

/**
 * @brief Constructeur pour calculer deux parametres
 * @param donnee
 */
Probleme::Probleme(Donnee donnee)
{

}

