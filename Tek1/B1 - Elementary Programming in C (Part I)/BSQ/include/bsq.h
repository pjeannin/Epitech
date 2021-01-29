/*
** EPITECH PROJECT, 2019
** BSQ.h
** File description:
** BSQ
*/

#ifndef BSQ_H_
#define BSQ_H_

struct square
{
    int x;
    int y;
    int lenght;
    int width;
    int find;
};

void put_str(char *str);
int my_getnbr(char *nbr);
struct square *struct_square_init(void);void find_square(char **map, int *nbr_col, int *nbr_line);
char **read_map(char *filepath, int *nbr_line, int *nbr_col);
void error_handling(char *filepath);
void error_message(char *str);
void set_struct_to(struct square *prev, int lenght, int line, int col);
int str_len(char *str);

#endif
