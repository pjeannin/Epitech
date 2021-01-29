/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** 101PONG
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "include/101pong.h"

void point_to_vector(struct coordinates *point1, struct coordinates *point2, struct coordinates *vector)
{
    vector->x = (point2->x) - (point1->x);
    vector->y = (point2->y) - (point1->y);
    vector->z = (point2->z) - (point1->z);
}

void final_point(struct coordinates *point2, struct coordinates *vector, struct coordinates *final_point, int n)
{
    final_point->x = ((point2->x) + ((vector->x) * n));
    final_point->y = ((point2->y) + ((vector->y) * n));
    final_point->z = ((point2->z) + ((vector->z) * n));
}

float find_angle(struct coordinates *vector, struct coordinates *p2)
{
    double len_v1;
    double len_v2;
    double angle;

    len_v1 = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
    len_v2 = sqrt(pow(vector->x, 2) + pow(vector->y, 2));
    angle = ((acos(len_v2/len_v1) * 180) / M_PI);
    if ((p2->z == 0) && (vector->z == 0))
        angle = 180;
    if (angle > 180)
        angle = 360 - angle;
    return (angle > 90 ? (180 - angle) : (angle));
}

void error(char **arg)
{
    int count;

    for (int i = 0; arg[7][i]; i++)
        if (arg[7][i] < '0' || arg[7][i] > '9') {
            write(2, &arg[7][i], 1);
            write(2, "syntax error", 14);
            exit(84);
        }
    for (int i = 1; arg[i]; i++) {
        count = 0;
        for (int j = 0; arg[i][j]; ++j) {
            if (arg[i][j] == '.')
                ++count;
            if (count > 1) {
                write(2, "syntax error", 13);
                exit(84);
            }
            if (('0' > arg[i][j] || arg[i][j] > '9') && arg[i][j] != '-' && arg[i][j] != '.') {
                write(2, "syntax error", 13);
                exit(84);
            }
        }
    }
}

void arg_int_struct(struct coordinates *p1, struct coordinates *p2, char **av)
{
    p1->x = atof(av[1]);
    p1->y = atof(av[2]);
    p1->z = atof(av[3]);
    p2->x = atof(av[4]);
    p2->y = atof(av[5]);
    p2->z = atof(av[6]);
}

int touch_the_bat(struct coordinates *point1, struct coordinates *point2, struct coordinates*vector)
{
    if (point1->z == point2->z && point1->z == 0)
        return (1);
    if ((point1->z >= 0) && (point2->z > point1->z))
        return (0);
    if ((point1->z <= 0) && (point2->z < point1->z))
        return (0);
    if(point1->z == point2->z)
        return (0);
    if (((point1->z < 0) && (point2->z >= 0)) || ((point2->z < 0) && (point1->z >= 0)))
        return (0);
    if (((point1->z <= 0) && (point2->z > 0)) || ((point2->z <= 0) && (point1->z > 0)))
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    struct coordinates *p1 = malloc(sizeof(coordinates_t));
    struct coordinates *p2 = malloc(sizeof(coordinates_t));;
    struct coordinates *v_speed = malloc(sizeof(coordinates_t));;
    struct coordinates *pn = malloc(sizeof(coordinates_t));
    double angle;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRIPTION\n    x0  ball abscissa at time t\n    y0  ball ordinate at time t\n    z0  ball altitude at time t\n    x1  ball abscissa at time t\n    y1  ball ordinate at time t\n    z1  ball altitude at time t\n    n   time shift (greater than or equal to zero, integer)");
        return (0);
    }
    if (ac != 8) {
        write(2, "Too few or too much arguments", 30);
        return (84);
    }
    error(av);
    arg_int_struct(p1, p2, av);
    point_to_vector(p1, p2, v_speed);
    final_point(p2, v_speed, pn, atoi(av[7]));
    angle = find_angle(v_speed, p2);
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\nAt time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", v_speed->x, v_speed->y, v_speed->z, atoi(av[7]), pn->x, pn->y, pn->z);
    if (touch_the_bat(p1, p2, v_speed))
        printf("The incidence angle is:\n%.2f degrees\n", angle);
    else
        printf("The ball won't reach the paddle.\n");
    return (0);
}
