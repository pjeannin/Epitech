/*
** EPITECH PROJECT, 2019
** inv_mat.c
** File description:
** 103cipher
*/

float **inv_2x2_mat(float **mat)
{
    float determinant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    float **Nmat = malloc(sizeof(float *) * 2);

    for (int i = 0; i < 2; ++i)
        Nmat[i] = malloc(sizeof(float) * 2);
    Nmat[0][0] = mat[1][1];
    Nmat[0][1] = mat[1][0];
    Nmat[1][0] = mat[0][1];
    Nmat[1][1] = mat[0][0];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            mat[i][j] = Nmat[i][j] * (1 / determinant);
}

float **inv_3x3_mat(float **mat)
{
    float determinent = ((mat[0][0] * mat[1][1] * mat[2][2]) + (mat[0][1] * mat[1][2] * mat[2][0]) + (mat[0][2] * mat[1][0] * mat[2][1]));
    float determinentb = ((mat[2][0] * mat[1][1] * mat[0][2]) + (mat[2][1] * mat[1][2] * mat[0][0]) + (mat[2][2] * mat[1][0] *mat[0][1]));
    float determinentf = determinent - determinentb;
    float **Nmat = malloc(sizeof(float *) * 3);

    // printf("matrice de base :\n");
    for (int i = 0; i < 3; ++i) {
        Nmat[i] = malloc(sizeof(float) * 3);
        // dispay_mat(i, 3, mat);
    }
    Nmat[0][0] = (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]);
    Nmat[1][0] = - ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]));
    Nmat[2][0] = (mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]);
    Nmat[0][1] = - ((mat[0][1] * mat[2][2]) - (mat[0][2] * mat[2][1]));
    Nmat[1][1] = (mat[0][0] * mat[2][2]) - (mat[0][2] * mat[2][0]);
    Nmat[2][1] = - ((mat[0][0] * mat[2][1]) - (mat[0][1] * mat[2][0]));
    Nmat[0][2] = (mat[0][1] * mat[1][2]) - (mat[0][2] * mat[1][1]);
    Nmat[1][2] = - ((mat[0][0] * mat[1][2]) - (mat[0][2] * mat[1][0]));
    Nmat[2][2] = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] = (Nmat[i][j] * (1 / determinentf));
    // printf("inverse :\n");
}

// int main()
// {
//     float **mat = malloc(sizeof(float *) * 3);
//     for (int i = 0; i < 3; ++i)
//         mat[i] = malloc(sizeof(float) * 3);
//     mat[0][0] = 82;
//     mat[0][1] = 111;
//     mat[0][2] = 109;
//     mat[1][0] = 101;
//     mat[1][1] = 114;
//     mat[1][2] = 32;
//     mat[2][0] = 83;
//     mat[2][1] = 0;
//     mat[2][2] = 0;
//     inv_3x3_mat(mat);
//     for (int i = 0; i < 3; ++i)
//         dispay_mat(i, 3, mat);
//     for (int i = 0; i < 3; ++i)
//         free(mat[i]);
//     free(mat);
// }