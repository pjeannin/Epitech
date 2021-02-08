/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** drawing
*/

#ifndef DRAWING_H_
#define DRAWING_H_

typedef struct point_s {
    double x;
    double y;
} point_t;

void draw_square(uint32_t **img, point_t point, size_t size,
uint32_t color);

#endif /* !DRAWING_H_ */
