/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** 102architect
*/

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void error_handling(int ac, char **av);

void add_translation(double **matrix, double x, double y)
{
    for (int i = 0; i < 3; ++i)
        matrix[i] = malloc(sizeof(double) * 3);
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = x;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = y;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}

void add_rotation(double **matrix, double o)
{
    o = (3.1415926535 * o) / 180;
    for (int i = 0; i < 3; ++i)
        matrix[i] = malloc(sizeof(double) * 3);
    matrix[0][0] = cos(o);
    matrix[0][1] = - sin(o);
    matrix[0][2] = 0;
    matrix[1][0] = sin(o);
    matrix[1][1] = cos(o);
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}

void add_scaling(double **matrix, double x, double y)
{
    for (int i = 0; i < 3; ++i)
        matrix[i] = malloc(sizeof(double) * 3);
    matrix[0][0] = x;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = y;
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}

void add_symetry(double **matrix, double o)
{
    o = (3.1415926535 * o) / 180;
    for (int i = 0; i < 3; ++i)
        matrix[i] = malloc(sizeof(double) * 3);
    matrix[0][0] = cos(2 * o);
    matrix[0][1] = sin(2 * o);
    matrix[0][2] = 0;
    matrix[1][0] = sin(2 * o);
    matrix[1][1] = - cos(2 * o);
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}

int add_arg_in_matrix(int ac, char **av, double ***matrix_tab)
{
    int i = 3;
    int k = 0;
    double **tmp;
    int matrix_index = 0;

    while (i < ac) {
        if (av[i][1] == 't') {
            printf("Translation along vector (%d, %d)\n", atoi(av[i + 1]), atoi(av[i + 2]));
            matrix_tab[matrix_index] = malloc(sizeof(double *) * 3);
            add_translation(matrix_tab[matrix_index], atof(av[i + 1]), atof(av[i + 2]));
            ++matrix_index;
            i += 3;
        } else if (av[i][1] == 'z') {
            printf("Scaling by factors %d and %d\n", atoi(av[i + 1]), atoi(av[i + 2]));
            matrix_tab[matrix_index] = malloc(sizeof(double *) * 3);
            add_scaling(matrix_tab[matrix_index], atof(av[i + 1]), atof(av[i + 2]));
            i += 3;
            ++matrix_index;
        } else if (av[i][1] == 'r') {
            printf("Rotation by a %d degree angle\n", atoi(av[i + 1]));
            matrix_tab[matrix_index] = malloc(sizeof(double *) * 3);
            add_rotation(matrix_tab[matrix_index], atof(av[i + 1]));
            i += 2;
            ++matrix_index;
        } else if (av[i][1] == 's') {
            printf("Reflection over an axis with an inclination angle of %d degrees\n", atoi(av[i + 1]));
            matrix_tab[matrix_index] = malloc(sizeof(double *) * 3);
            add_symetry(matrix_tab[matrix_index], atof(av[i + 1]));
            i += 2;
            ++matrix_index;
        }
    }
    for (int j = matrix_index - 1; k <= j; --j) {
        tmp = matrix_tab[k];
        matrix_tab[k] = matrix_tab[j];
        matrix_tab[j] = tmp;
        ++k;
    }
    return (matrix_index);
}

double **mul_matrix(double **mat1, double **mat2, int line, int col)
{
    double **res = malloc(sizeof(double *) * line);

    for (int i = 0; i < line; ++i) {
        res[i] = malloc(sizeof(double) * 3);
        for (int j = 0; j < col; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < col; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return (res);
}

double **mul_matrix_tab(double ***matrix_tab, int line, int col, int tab_len)
{
    double **res = matrix_tab[0];
    for (int i = 1; i < tab_len; ++i)
        res = mul_matrix(res, matrix_tab[i], line, col);
    return (res);
}

void free_tab(double ***matrix_tab, int tab_len)
{
    for (int i = 0; i < tab_len; ++i) {
        for (int j = 0; j < 3; ++j)
            free(matrix_tab[i][j]);
        free(matrix_tab[i]);
    }
    free(matrix_tab);
}

void dispay_mat(int i, double **mat_res)
{
    int print;

    for (int j = 0; j < 3; ++j) {
        if (mat_res[i][j] < 0 && mat_res[i][j] > -0.001)
            mat_res[i][j] = 0;
        if (j != 2)
            printf("%-8.2f", mat_res[i][j]);
        else
            printf("%.2f", mat_res[i][j]);
    }
}

int main(int ac, char **av)
{
    int tab_len = 0;
    double ***matrix_tab = malloc(sizeof(double **) * ac);
    double **mat_res;
    double a;
    double b;

    error_handling(ac, av);
    tab_len = add_arg_in_matrix(ac, av, matrix_tab);
    mat_res = mul_matrix_tab(matrix_tab, 3, 3, tab_len);
    a = ((mat_res[0][0] * atof(av[1])) + (mat_res[0][1] * atof(av[2])) + mat_res[0][2]);
    b = ((mat_res[1][0] * atof(av[1])) + (mat_res[1][1] * atof(av[2])) + mat_res[1][2]);
    if (a < 0 && a > -0.001)
        a = 0;
    if (b < 0 && b > -0.001)
        b = 0;
    for (int i = 0; i < 3; ++i) {
        dispay_mat(i, mat_res);
        printf("\n");
    }
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(av[1]), atof(av[2]), a, b);
    free_tab(matrix_tab, tab_len);
}