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
    static double P(int S, int K, double lambda, double mu, int t);
    static double Pq(int S, int K, double lambda, double mu, int t);
    static double Qj(int S, int K, double lambda, double mu, int j);
    static double Q0(int S, int K, double lambda, double mu, int j);

private:
    static int factorial(int x);
};

#endif // CALCULATION_H
