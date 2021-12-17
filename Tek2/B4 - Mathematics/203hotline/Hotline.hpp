/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-pierre.jeannin
** File description:
** Hotline
*/

#ifndef HOTLINE_HPP_
#define HOTLINE_HPP_

#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>

class Hotline {
    public:
        Hotline();
        ~Hotline();
        const int getCallDuration() const;
        const int getN() const;
        const int getK() const;
        void setCallDuration(int newValue);
        void setN(int newValue);
        void setK(int newValue);
        long double computeBinomialCoef();
        double factorial(int number);
        void binomialLaw();
        void poissonLaw();
        long double computeBinomiale(double P, int N, int K);
        double computePoisson(double lambda, int K);
    protected:
    private:
        long double BinomialCoef(int N, int K);
        int callDuraiton;
        int n;
        int k;
};

#endif /* !HOTLINE_HPP_ */
