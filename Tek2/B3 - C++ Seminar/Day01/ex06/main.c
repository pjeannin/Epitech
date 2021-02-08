/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "menger.h"
#include "bitmap.h"
#include "drawing.h"

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;

    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t header;

    make_bmp_info_header(&header, size);
    write(fd, &header, sizeof(header));
}

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

void create_bitmap_from_buffer(char *name, size_t size, unsigned int *buffer)
{
    int fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer)); close(fd);
}

int main(int argc, char **argv)
{
    unsigned int *buffer = NULL;
    unsigned int **img = NULL;
    point_t point;

    if (error_handling(argc, argv))
        return (84);
    point.x = 0;
    point.y = 0;
    buffer = malloc(atoi(argv[2]) * atoi(argv[2]) * sizeof(*buffer));
    img = malloc(atoi(argv[2]) * sizeof(*img));
    initialize_image(atoi(argv[2]), buffer, img);
    draw_square(img, point, atoi(argv[2]), 0X00000000);
    img = menger(point, atoi(argv[2]), atoi(argv[3]), img);
    create_bitmap_from_buffer(argv[1], atoi(argv[2]), buffer);
    return (0);
}