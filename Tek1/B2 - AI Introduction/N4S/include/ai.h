/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#ifndef AI_H_
#define AI_H_

void is_end(char *str);
void is_end_bis(char *str);
void set_wheels(float *wheels, float val);
float *read_lidar_command(char *api_ret);
void interpret_lidar_end(float *tab, float *wheels);
void interpret_lidar(float *tab, float *wheels);
void understand_lidar(char *api_ret, float *wheels);
int str_len(char *str);
int strncomp(char *str1, char *str2, int n);

#endif /* !AI_H_ */
