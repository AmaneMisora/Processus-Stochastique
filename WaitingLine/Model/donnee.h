#ifndef DONNEE_H
#define DONNEE_H


class Donnee
{
private:
    int valeur_K;
    int valeur_S;
    int nb_client;
    int unite_client;
    int nb_service;
    int unite_service;

public:
    Donnee();
    ~Donnee();

    int getValeur_K() const;
    void setValeur_K(int value);
    int getValeur_S() const;
    void setValeur_S(int value);
    int getNb_client() const;
    void setNb_client(int value);
    int getUnite_client() const;
    void setUnite_client(int value);
    int getNb_service() const;
    void setNb_service(int value);
    int getUnite_service() const;
    void setUnite_service(int value);

};

#endif // DONNEE_H
