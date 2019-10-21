#include "calculation.h"

Calculation::Calculation()
{
}

double Calculation::L(int S, int K, double lambda, double mu)
{

    qDebug() << S << K << lambda << mu;
    if(S == 1)
    {
        if(K == 0)
        {
            return lambda / (mu - lambda);
        }
    }
}
