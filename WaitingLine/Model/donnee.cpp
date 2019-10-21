#include "donnee.h"

int Donnee::getValeur_K() const
{
    return valeur_K;
}

void Donnee::setValeur_K(int value)
{
    valeur_K = value;
}

int Donnee::getValeur_S() const
{
    return valeur_S;
}

void Donnee::setValeur_S(int value)
{
    valeur_S = value;
}

int Donnee::getNb_client() const
{
    return nb_client;
}

void Donnee::setNb_client(int value)
{
    nb_client = value;
}

int Donnee::getUnite_client() const
{
    return unite_client;
}

void Donnee::setUnite_client(int value)
{
    unite_client = value;
}

int Donnee::getNb_service() const
{
    return nb_service;
}

void Donnee::setNb_service(int value)
{
    nb_service = value;
}

int Donnee::getUnite_service() const
{
    return unite_service;
}

void Donnee::setUnite_service(int value)
{
    unite_service = value;
}

Donnee::Donnee()
{

}
