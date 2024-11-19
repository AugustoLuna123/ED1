#include "seno.h"

#include <stdio.h>

long int fatorial(int);

long int pot(int, int);

double taylor(int, int, int, double);

double seno(int x, int n) {
    return taylor(x, n, 0, 1.0);
}

long int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

long int pot(int b, int n) {
    if (n == 0) {
        return 1;
    }
    return b * pot(b, n - 1);
}

double taylor(int x, int n, int i, double factor) {
    if (i >= n) {
        return 0;
    }
    int power = 2 * i + 1;
    double term = factor * pot(x, power) / fatorial(power);
    return term + taylor(x, n, i + 1, -factor);
}