//
// Created by Legion on 07.09.2021.
//

#include "solvefunctions.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double NOT_ROOT = INFINITY;



int IsApproxZero (double number) {
    const double PRECISION = 0.0000005; /*!< константа, проверяющая допустимость погрешности нахождения корней */
    if (!isfinite(number)) {
        return 1;
    }
    return fabs(number) < PRECISION;
}

void PrintStartingMessage () {
    printf("This program is created to solve equations of the form ax² + bx + c = 0. \n"
           "Please enter 3 coefficients of your equation in this order: a, b, c. \n"
           "Remember that in a quadratic equation, the coefficient a must not be 0. \n");
}

int SolveEquation (double coef_a, double coef_b, double coef_c, double* x1, double* x2) {
    double disc = 0;

    if (IsApproxZero(coef_a)) {
        *x2 = NOT_ROOT;
        return SolveLinearEquation(coef_b, coef_c, x1);
    }

    disc = coef_b * coef_b - 4 * coef_a * coef_c;
    if (disc < 0) {
        *x1 = *x2 = NOT_ROOT;
        return 0;
    } else if (IsApproxZero(disc)) {
        *x1 = (-coef_b) / (2 * coef_a);
        *x2 = NOT_ROOT;
        return 1;
    } else {
        *x1 = (-coef_b - sqrt(disc)) / (2 * coef_a);
        *x2 = (-coef_b + sqrt(disc)) / (2 * coef_a);
        return 2;
    }
}

int SolveLinearEquation (double b, double c, double* x1) {
    if (IsApproxZero(b)) {
        if (IsApproxZero(c)) {
            *x1 = NOT_ROOT;
            return INFIN_ROOTS;
        } else {
            return 0;
        }
    } else {
        if (IsApproxZero(c)) {
            *x1 = 0;
        } else {
            *x1 = -c / b;
        }
        return 1;
    }
}

void RunEquationSolving () {
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double x1 = 0, x2 = 0;

    PrintStartingMessage();

    GetCoefficients(&coef_a, &coef_b, &coef_c);
    int roots_number = SolveEquation(coef_a, coef_b, coef_c, &x1, &x2);

    PrintResult(x1, x2, roots_number);
}

void GetCoefficients (double* coef_a, double* coef_b, double* coef_c) {
    int success_scan = scanf("%lf %lf %lf", coef_a, coef_b, coef_c);
    if (success_scan != 3) {
        scanf("%*[^\n]");
        printf("Please enter valid coefficients. \n");
        GetCoefficients(coef_a, coef_b, coef_c);
    }
}

