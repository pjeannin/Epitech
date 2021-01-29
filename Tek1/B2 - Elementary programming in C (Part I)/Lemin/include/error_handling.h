/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** error_handling
*/

#ifndef ERROR_HANDLING_H_
#define ERROR_HANDLING_H_

char **error_handling(int ac, char **av);
char **input_is_wrong(void);
int check_first_line(char **input);
int find_cmd(char **input, char *cmd);
int check_start_end(char **input, int *start, int *end);
int check_pipes(char **input, int start, int end);
int find_pipe_start(char **input);
int check_line(char *line);
char **remove_comments(char **input);

#endif /* !ERROR_HANDLING_H_ */
