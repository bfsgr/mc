#include <stdio.h>
#include <math.h>

double libc_sin(double x) {
    return sin(x);
}

double taylor(double x){
    static const double K = -1.0/6.0;
    static const double M = 1.0/120.0;
    static const double N = -1.0/5040.0;
    static const double P = 1.0/362880.0;
    static const double Q = -1.0/39916800.0;

    double y = x*x;

    return x * (1 + y * (K + y * (M + y * (N + y * (P + Q * y)))));
}

double pade(double x) {
    static const double P1 = -241.0/1650.0;
    static const double P2 = 601.0/118800.0;
    static const double P3 = -121.0/2268000.0;
    static const double B = 17.0/825.0;
    static const double D = 19.0/118800.0;

    double y = x*x;

    double p = x * (1+ y * (P1 + y * (P2 + y * P3)));
    double q = 1 + y * (B + D * y);

    return p/q;
}