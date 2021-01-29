/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** my_ls
*/

#include <dirent.h>

#ifndef MY_LS_H_
#define MY_LS_H_

typedef struct file_s {
    char *name;
    int type;
    int size;
    char *right;
    char *a_time_brut;
    char *m_time_brut;
    char *a_time;
    char *m_time;
    char *owner;
    char *group;
    int link;
    struct file_s *next;
    struct file_s *prev;
} file_t;

int my_getnbr(char const *str);
void display_lst(file_t *list);
void display_lsat(file_t *list);
int convert_month(char *date);
void disp_R(file_t *list, char *dirname);
int get_day(char *date);
file_t *sort_a_time(file_t *list);
int str_len(char *str);
file_t *init_list(void);
char *concat_str(char *str1, char *str2);
file_t *move_beginning(file_t *list);
file_t *move_end(file_t *list);
void display_F(file_t *list);
char *convert_time(char *date);
int comp_str(char *str, char *str2);
file_t *fill_list(file_t *list, char *dirname, struct dirent *file_read,
struct stat file);
file_t *sort(file_t *list);
file_t *swap_node(file_t *list);
void check_flags(file_t *list, int ac, char **av);
void display_la(file_t *list);
void display_lsa(file_t *list);
void display_l(file_t *list);
int find_longer(file_t *list);
void display_d(file_t *list);
void display_ls(file_t *list);
void display_r(file_t *list);
void dis_all(file_t *list);
char *char_from_int(int nbr);
DIR *open_dir(char *dirname);
void my_ls(int ac, char **av, char *dirname);
void free_list(file_t *list);
void dis_all_F(file_t *list);

#endif /* !MY_LS_H_ */
