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
 * @brief Getter : Type_prob
 */
int Probleme::getType_prob() const
{
    return type_prob;
}

/**
 * @brief Setter : Type_prob
 */
void Probleme::setType_prob(int value)
{
    type_prob = value;
}

/**
 * @brief Constructeur par défaut
 */
Probleme::Probleme()
{
    
}

/**
 * @brief Constructeur par analyser la donnée
 * @param donnee
 */
Probleme::Probleme(Donnee donnee)
{

}

/**
 * @brief Initialiser la type de probleme
 * @details 1: M|M|1|infinité; 2: M|M|1|K;  3:M|M|S|infinité
 */
void Probleme::initialiserType()
{
    if(this->donnee.getNb_service() == 1) {
        //serveur unique
//        if()
    } else {
        // type de probleme : M|M|S|infinité
        this->setType_prob(3);
    }
}

