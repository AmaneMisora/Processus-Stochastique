#ifndef CALCULATION_H
#define CALCULATION_H

#include <QDebug>
#include <QtMath>

class Calculation
{
public:
    Calculation();

    static double L(int S, int K, double lambda, double mu);
    static double Lq(int S, int K, double lambda, double mu);
    static double W(int S, int K, double lambda, double mu);
    static double Wq(int S, int K, double lambda, double mu);
    static double Q(int S, int K, double lambda, double mu, int j);

private:
    static int factorial(int x);
};

#endif // CALCULATION_H
