/*
** EPITECH PROJECT, 2019
** 103cypher.h
** File description:
** 103cypher
*/

#ifndef CYPHER_H_
#define CYPHER_H_

typedef struct mat_s {
    int line;
    int col;
    float **mat;
} mat_t;

int str_len(char *str);
float **mul_matrix(float **mat1, float **mat2, int line, int col);
char **my_str_to_word_array(char const *str, int *cut);
float **inv_3x3_mat(float **mat);
float **inv_2x2_mat(float **mat);
float invert_mat(float **mat, int k);

#endif
