/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchsitck
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

int str_len(char *str);
void put_char(char c);
void put_str(char *str);
int **creat_tab(int size);
void free_tab(int **tab, int size);
int **update_game_board(int line, int nb_matches, int **tab, int size);
void print_space(int **tab, int i, int size);
void print_game_board(int **tab, int size);
int error_handling(char *line, char *matches, int ac);
int my_getnbr(char const *str);
void put_nbr(int nbr);
int check_end(int **tab, int size);
int get_line(int **tab, int size, int *go);
int get_matches(int **tab, int line, int *go);
int **player(int **tab, int size, int max_matchs);
int **ai(int **tab, int size, int max_matches);
int matchstick(int **tab, int size, int max_matches);
void disp(int line, int matches, char type);

#endif /* !MATCHSTICK_H_ */
