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

private:
    static int factorial(int x);
};

#endif // CALCULATION_H
