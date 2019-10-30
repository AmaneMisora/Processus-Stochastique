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
 * retourne -2 si le calcul à échoué
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::L(int S, int K, double lambda, double mu)
{
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

/**
 * @brief Calculation::Lq
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @return Le nombre moyen de personnes dans la queue
 * retourne -1 en cas de blocage de la file
 * retourne -2 si le calcul à échoué
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::Lq(int S, int K, double lambda, double mu)
{
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

/**
 * @brief Calculation::W
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @return Le temps moyen d'attente dans le système
 * retourne -1 en cas de blocage de la file
 * retourne -2 si le calcul à échoué
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::W(int S, int K, double lambda, double mu)
{
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

/**
 * @brief Calculation::Wq
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @return Le temps moyen d'attente dans la queue
 * retourne -1 en cas de blocage de la file
 * retourne -2 si le calcul à échoué
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::Wq(int S, int K, double lambda, double mu)
{
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

/**
 * @brief Calculation::Q
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @param j
 * @return La probablité de se trouver dans l'état j à l'équilibre
 * retourne -1 en cas de blocage de la file
 * retourne -2 si le calcul à échoué
 * retourne nan en  cas d'erreur de calcul
 */
double Calculation::Q(int S, int K, double lambda, double mu, int j)
{
    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0)
        {
            return qPow(rho, j) * (1 - rho);
        }
        else
        {
            if(rho == 1)
            {
                return 1 / (K+1);
            }
            else
            {
                double num = (1 - rho) * qPow(rho, j);
                double denom = 1 - qPow(rho, K+1);
                return num / denom;
            }
        }
    }
    else
    {
        double rho = lambda / (mu * S);

        if(j == 0) // Q0
        {
            double sum = 0;

            for(int i=0; i<S-1; i++)
            {
                sum += qPow(rho * S, j) / factorial(j);
                sum += qPow(rho * S, S) / (factorial(S) * (1-rho));
            }

            return 1/sum;
        }
        else if(j < S)
        {
            return ( qPow(rho * S, j) / factorial(j) ) * Q(S, K, lambda, mu, 0);
        }
        else
        {
            return ( qPow(S, S) * qPow(rho, j) / factorial(S) ) * Q(S, K, lambda, mu, 0);
        }
    }
}

/**
 * @brief Calculation::factorial
 * @param x
 * @return la factorielle de x par récurcivité
 */
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

/**
 * @brief Calculation::P
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @param t
 * @return La probabilité que le temps d'attente dans le système soit supérieur à t
 */
double Calculation::P(int S, int K, double lambda, double mu, int t)
{
    double q0;
    double p;

    // Calcul de rho
    double rho;
    if(S == 1) {
        rho = lambda / mu;
        q0 = Q(S,K,lambda,mu,0);
    } else {
        rho = lambda / (mu * S);
        q0 = Q(S,K,lambda,mu,0);
    }

    // Calcul de P selon le type de queue
    if(S == 1)
    {
        if(K == 0) //M | M | 1
        {
            p = qExp(- mu * (1-rho) * t);
        }
        else // M | M | 1 | K
        {
            // J'ai pas trouvé la formule
            p = -2;
        }

    }
    else
    {
        if(K == 0) // M | M | S | K (On ne sais pas faire)
        {
            double right_1_up = 1 - (qExp(0-(mu*t*(S-1-rho*S))));
            double right_1_down = S - 1 - rho*S;
            double right_2 = (q0*qPow(rho*S, 2)) / (factorial(S)* (1 - rho));
            p = qExp(0 - mu*t) * (1+right_2 * (right_1_up/right_1_down));
        }
        else // M | M | S |
        {
            p = -2;
        }
    }

    return p;
}

/**
 * @brief Calculation::Pq
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @param t
 * @return
 * Durée d’attente sans service
 */
double Calculation::Pq(int S, int K, double lambda, double mu, int t)
{
    double q0;
    double rho;
    if(S == 1) {
        rho = lambda / mu;
        q0 = Q(S,K,lambda,mu,0);
    } else {
        rho = lambda / (mu * S);
        q0 = Q(S,K,lambda,mu,0);
    }
    double Pq0;
    Pq0 = (q0 * qPow(rho*S, S)) / (factorial(S) * (1 - rho));
    if(t == 0.0) {
        return  Pq0;
    }
    double Pqt = qExp(0 - S*mu*t*(1 - rho) * Pq0);
    return Pqt;
}




