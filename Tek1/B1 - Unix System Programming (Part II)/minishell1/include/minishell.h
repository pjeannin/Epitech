/*
** EPITECH PROJECT, 2020
** minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL
#define MINISHELL

#define PROMPT  "$>>> "
#define IGNORE_EXIT 1234567

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
    struct env_s *prev;
} env_t;

char *clean_cmd(char *cmd);
char *concat_str(char *str1, char *str2);
char *concat_sstr(char *str1, char *str2);
char **creat_tab(env_t **env_list);
char **create_word_list(char *str, env_t **env_list);
char *find_home(env_t *list);
char *find_val(env_t **env_list, char *name);
char **get_argv(char *command, env_t **env_list);
char **list_to_tab(env_t *env_list);
char *set_name(char *command);
char *set_val(char *command);

env_t *move_beginning(env_t *list);
env_t *move_end(env_t *list);
env_t *transform_env(char **envp);

int count_spaces(char *str);
int comp_str(char *str1, char *str2);
int exit_command(char *command, env_t **env_list);
int get_command(char *command, env_t **envp);
int my_getnbr(char *str);
int is_root(env_t **env_list);
int list_len(env_t *list);
int minishell(env_t **envp);
int str_len(char *str);

void cd_command(char *command, env_t **env_list);
void env_command(char *command, env_t *env_list);
void exe_command(char *command, env_t **env_list);
void free_list(env_t *list);
void free_tab(char **tab);
void put_error_str(char *str);
void put_nbr(int nbr);
void put_str(char *str);
void setenv_command(char *command, env_t **env_list);
void unsetenv_command(char *command, env_t **env_list);

#endif /* !minishell */
