/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-pierre.jeannin
** File description:
** Hotline
*/

#include "Hotline.hpp"

Hotline::Hotline() : callDuraiton(0), n(0), k(0)
{
}

Hotline::~Hotline()
{
}

const int Hotline::getCallDuration() const { return (callDuraiton); }

const int Hotline::getN() const { return (n); }

const int Hotline::getK() const { return (k); }

void Hotline::setCallDuration(int newValue) { callDuraiton = newValue; }

void Hotline::setN(int newValue) { n = newValue; }

void Hotline::setK(int newValue) { k = newValue; }

double Hotline::factorial(int number)
{
    if (number != 0) {
        double res = 1;
        for (double i = 2; i < number + 1; ++i)
            res *= i;
        return (res);
    }
    return (1);
}

long double Hotline::computeBinomialCoef()
{
    if (k > n)
        return (0);
    long double res = 1;
    for (int i = 1; i <= k; ++i) {
        res = (res / i) * (n--);
    }

    return (res);
}

long double Hotline::BinomialCoef(int N, int K)
{
    if (K > N)
        return (0);
    long double res = 1;
    for (int i = 1; i <= K; ++i) {
        res = (res / i) * (N--);
    }

    return (res);
}

long double Hotline::computeBinomiale(double P, int N, int K)
{
    return (BinomialCoef(N, K) * pow(P, K) * pow(1 - P, N - K));
}

double Hotline::computePoisson(double lambda, int K)
{
    try {
        return ((exp(0 - lambda) * pow(lambda, K)) / factorial(K));
    } catch (std::exception e) {
        return (0);
    }
}

void Hotline::binomialLaw()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    double overload = 0;
    double res;
    double p = (double)callDuraiton / (8 * 60 * 60);

    for (int i = 0; i <= 50; ++i) {
        std::cout << i << " -> " << std::fixed << std::setprecision(3) << (res = computeBinomiale(p, 3500, i));
        if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24 || i == 29 || i == 34 || i == 39 || i == 44 || i == 49 || i == 50)
            std::cout << std::endl;
        else
            std::cout << "\t";
        if (i > 25)
            overload += res;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Overload: " << std::setprecision(1) << (overload * 100) << "%" << std::endl;
    double duration = (double)std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << "Computation time: " << std::setprecision(2) << duration / 1000 << " ms" << std::endl;
}

void Hotline::poissonLaw()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    double overload = 0;
    double res;
    double p = ((double)callDuraiton / (8 * 60 * 60)) * 3500;

    for (int i = 0; i <= 50; ++i) {
        std::cout << i << " -> " << std::fixed << std::setprecision(3) << (res = computePoisson(p, i));
        if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24 || i == 29 || i == 34 || i == 39 || i == 44 || i == 49 || i == 50)
            std::cout << std::endl;
        else
            std::cout << "\t";
        if (i > 25)
            overload += res;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Overload: " << std::setprecision(1) << (overload * 100) << "%" << std::endl;
    double duration = (double)std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << "Computation time: " << std::setprecision(2) << duration / 1000 << " ms" << std::endl;
}