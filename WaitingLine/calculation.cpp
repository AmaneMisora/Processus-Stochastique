#include "calculation.h"

Calculation::Calculation()
{
}

<<<<<<< HEAD
/**
 * @brief Calculation::L
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * @return le nombre moyen de personnes dans le système
 *
 */
=======
>>>>>>> master
double Calculation::L(int S, int K, double lambda, double mu)
{

    qDebug() << S << K << lambda << mu;
<<<<<<< HEAD

    if(S == 1)
    {
        double rho = lambda / mu;

        if(K == 0)
        {
            if(rho > 1)
            {
                return lambda / (mu - lambda);
            }
            else
            {
                return -1;
            }
        }
        else
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

    return -1;
=======
    if(S == 1)
    {
        if(K == 0)
        {
            return lambda / (mu - lambda);
        }
    }
>>>>>>> master
}
