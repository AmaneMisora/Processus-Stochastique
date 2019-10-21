#ifndef CALCULATION_H
#define CALCULATION_H

#include <QDebug>
#include <QtMath>

class Calculation
{
public:
    Calculation();

    static double L(int S, int K, double lambda, double mu);
};

#endif // CALCULATION_H
