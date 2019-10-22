#include "calculation.h"

Calculation::Calculation()
{
}

/**
 * @brief Calculation::L
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @return le nombre moyen de personnes dans le système
 * retourne -1 en cas de blocage de la file
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::L(int S, int K, double lambda, double mu)
{

    qDebug() << S << K << lambda << mu;

    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0) // M | M | 1
        {
            if(rho < 1)
            {
                return lambda / (mu - lambda);
            }
            else
            {
                return -1;
            }
        }
        else // M | M | 1 | K
        {
            if(rho == 1)
            {
                return K/2;
            }
            else
            {
                double num = rho * ( 1 - (K+1) * qPow(rho, K) + K * qPow(rho, K+1) );
                double denom = (1 - rho) * (1 - qPow(rho, K+1));
                return num / denom;
            }
        }
    }
    else // M | M | S
    {
        return Lq(S, K, lambda, mu) + (lambda / mu);
    }

    return -2;
}

double Calculation::Lq(int S, int K, double lambda, double mu)
{
    qDebug() << S << K << lambda << mu;

    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0) // M | M | 1
        {
            if(rho < 1)
            {
                return qPow(lambda, 2) / (mu * (mu - lambda));
            }
            else
            {
                return -1;
            }
        }
        else // M | M | 1 | K
        {
            if(rho == 1)
            {
                return L(S, K, lambda, mu) - (1 - ( 1/(K+1) ) );
            }
            else
            {
                // Calcul de q0
                double q0 = (1-rho) / (1 - qPow(rho, K+1));

                return L(S, K, lambda, mu) - (1 - q0);
            }
        }
    }
    else // M | M | S
    {
        double rho = lambda / (mu * S);

        // Calcule de Q0
        double sum = 0;

        for(int j = 0; j < S-1; j++)
        {
            sum += ( (qPow((rho * S), j) /  factorial(j) ) + ( (qPow((rho * S), S) / (factorial(S)*(1-rho)))));
        }

        double q0 = 1/sum;

        return ( q0 * qPow(S,S) * qPow(rho, S+1) / factorial(S) ) * 1 / qPow((1-rho), 2);
    }

    return -2;
}

double Calculation::W(int S, int K, double lambda, double mu)
{
    qDebug() << S << K << lambda << mu;

    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0) // M | M | 1
        {
            if(rho < 1)
            {
                return L(S,K,lambda,mu) / lambda;
            }
            else
            {
                return -1;
            }
        }
        else // M | M | 1 | K
        {
            return -2;

        }
    }
    else // M | M | S
    {
        return Wq(S, K, lambda, mu) + (1/mu);
    }

    return -2;
}

double Calculation::Wq(int S, int K, double lambda, double mu)
{
    qDebug() << S << K << lambda << mu;

    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0) // M | M | 1
        {
            if(rho < 1)
            {
                return W(S,K,lambda,mu) - (1 / mu) ;
            }
            else
            {
                return -1;
            }
        }
        else // M | M | 1 | K
        {
            return -2;

        }
    }
    else // M | M | S
    {
        return Lq(S, K, lambda, mu) / lambda;
    }

    return -2;
}

int Calculation::factorial(int x)
{
    if(x < 2)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}
