/*
** EPITECH PROJECT, 2019
** mul_matrix.c
** File description:
** 103cypher
*/

#include <stdlib.h>

float **mul_matrix(float **mat1, float **mat2, int line, int col)
{
    float **res = malloc(sizeof(float *) * line);

    for (int i = 0; i < line; ++i) {
        res[i] = malloc(sizeof(float) * 3);
        for (int j = 0; j < col; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < col; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return (res);
}