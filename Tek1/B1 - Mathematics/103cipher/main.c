/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** 102cypher
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "103cypher.h"

char *char_from_int(int nbr)
{
    int cpy = nbr;
    int len = 0;
    int i = 0;
    char *n;

    while (cpy > 0) {
        ++len;
        cpy /= 10;
    }
    if (len == 0)
        return("0");
    n = malloc(sizeof(char) * len);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    return (n);
}

void dispay_mat3(int i, int col, float **mat_res)
{
    for (int j = 0; j < col; ++j) {
        if (mat_res[i][j] < 0 && mat_res[i][j] > -0.001)
            mat_res[i][j] = 0;
        if (j != col - 1)
            printf("%-8.3f", mat_res[i][j]);
        else
            printf("%.3f", mat_res[i][j]);
    }
    printf("\n");
}

void dispay_mat(int i, int col, float **mat_res)
{
    for (int j = 0; j < col; ++j) {
        if (mat_res[i][j] < 0 && mat_res[i][j] > -0.001)
            mat_res[i][j] = 0;
        if (j != col - 1)
            printf("%-8.0f", mat_res[i][j]);
        else
            printf("%.0f", mat_res[i][j]);
    }
    printf("\n");
}

void dispay_mat_dec(int i, int col, float **mat_res)
{
    for (int j = 0; j < col; ++j)
        printf("%c", (char)mat_res[i][j]);
}


void display_encrypted_str(float **mat, int line, int col)
{
    for (int i = 0; i < line; ++i)
        for (int j = 0; j < col; ++j) {
            if (i == line - 1 && j == col - 1)
                printf("%.0f\n", mat[i][j]);
            else
                printf("%.0f ", mat[i][j]);
        }
}

void decrypting(mat_t *key_mat, char *str)
{
    int len = 0;
    int index = 0;
    mat_t *str_mat = malloc(sizeof(mat_t));
    char **str_tab = my_str_to_word_array(str, &len);
    float **res;

    str_mat->col = key_mat->col;
    str_mat->line = len / str_mat->col;
    if (len % str_mat->col)
        ++str_mat->line;
    str_mat->mat = malloc(sizeof(float *) * str_mat->line);
        for (int i = 0; i < str_mat->line; ++i) {
        str_mat->mat[i] = malloc(sizeof(float) * str_mat->col);
        for (int j = 0; j < str_mat->col; ++j) {
            if (index < len) {
                str_mat->mat[i][j] = atoi(str_tab[index]);
            } else
                str_mat->mat[i][j] = 0;
            ++index;
        }
    }
    if (key_mat->col == 3) {
        inv_3x3_mat(key_mat->mat);
        for (int i = 0; i < 3; ++i)
            dispay_mat3(i, 3, key_mat->mat);
    } else if (key_mat->col == 2) {
        inv_2x2_mat(key_mat->mat);
        for (int i = 0; i < 2; ++i)
            dispay_mat3(i, 2, key_mat->mat);
    } else if (key_mat->col == 1) {
        printf("%.3f\n", 1/(key_mat->mat[0][0]));
        for (int i = 0; i < str_mat->line; ++i)
            for (int j = 0; j < str_mat->col; ++j)
                str_mat->mat[i][j] = str_mat->mat[i][j] / key_mat->mat[0][0];
    }
    printf("\nDecrypted message:\n");
    if (key_mat->col != 1) {
        res = mul_matrix(str_mat->mat, key_mat->mat, str_mat->line, str_mat->col);
        for (int i = 0; i < str_mat->line; ++i)
            dispay_mat_dec(i, str_mat->col, res);
    } else
        for (int i = 0; i < str_mat->line; ++i)
            dispay_mat_dec(i, str_mat->col, str_mat->mat);
}

void encrypting(mat_t *key_mat, char *str)
{
    mat_t *str_mat = malloc(sizeof(mat_t));
    int index = 0;
    float **res;

    printf("\nEncrypted message:\n");
    str_mat->col = key_mat->col;
    str_mat->line = str_len(str) / str_mat->col;
    if (str_len(str) % str_mat->col)
        ++str_mat->line;
    str_mat->mat = malloc(sizeof(float *) * str_mat->line);
    for (int i = 0; i < str_mat->line; ++i) {
        str_mat->mat[i] = malloc(sizeof(float) * str_mat->col);
        for (int j = 0; j < str_mat->col; ++j) {
            if (index < str_len(str)) {
                str_mat->mat[i][j] = (int)str[index];
            } else
                str_mat->mat[i][j] = 0;
            ++index;
        }
    }
    res = mul_matrix(str_mat->mat, key_mat->mat, str_mat->line, str_mat->col);
    display_encrypted_str(res, str_mat->line, str_mat->col);
}

int error_handling(int ac, char **av)
{
    if (ac != 4) {
        write(2, "Invalid arguments", 17);
        return (1);
    }
    if (str_len(av[3]) != 1 || (av[3][0] != '0' && av[3][0] != '1')) {
        write(2, "Invalid arguments", 17);
        return (1);
    }
    return (0);
}

mat_t *create_key_mat(char *key)
{
    int index = 0;
    mat_t *key_mat = malloc(sizeof(mat_t));

    key_mat->line = 0;
    while (str_len(key) > (key_mat->line * key_mat->line))
        ++(key_mat->line);
    key_mat->mat = malloc(sizeof(float *) * key_mat->line);
    for (int i = 0; i < key_mat->line; ++i) {
        key_mat->mat[i] = malloc(sizeof(float) * key_mat->line);
        for (int j = 0; j < key_mat->line; ++j) {
            if (index < str_len(key))
                key_mat->mat[i][j] = (int)key[index];
            else
                key_mat->mat[i][j] = 0;
            ++index;
        }
    }
    key_mat->col = key_mat->line;
    return (key_mat);
}

int main(int ac, char **av)
{
    char *str = av[1];
    char *key = av[2];
    mat_t *key_mat;
    int flag;

    if (error_handling(ac, av))
        return (84);
    flag = atoi(av[3]);
    key_mat = create_key_mat(key);
    printf("Key matrix:\n");
    if (flag)
        decrypting(key_mat, str);
    else {
        for (int i = 0; i < key_mat->line; ++i)
            dispay_mat(i,  key_mat->col, key_mat->mat);
        encrypting(key_mat, str);
    }
    return (0);
}