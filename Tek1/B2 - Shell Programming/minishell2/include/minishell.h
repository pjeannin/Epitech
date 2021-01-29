/*
** EPITECH PROJECT, 2020
** minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL
#define MINISHELL

#define PROMPT  "$>>> "
#define READING_PROMPT "? "
#define IGNORE_EXIT 1234567
#define NO_FILE ": No such file or directory.\n"

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
    struct env_s *prev;
} env_t;

typedef struct read_s {
    char *read;
    struct read_s *next;
    struct read_s *prev;
} read_t;

char *clean_cmd(char *cmd);
char *concat_str(char *str1, char *str2);
char *concat_sstr(char *str1, char *str2);
char **creat_tab(env_t **env_list);
char **create_word_list(char *str, env_t **env_list);
char *find_home(env_t *list);
char *find_val(env_t **env_list, char *name);
char **get_argv(char *command, env_t **env_list);
char **cut_cmd(char *command, char sep);
char **list_to_tab(env_t *env_list);
char ** cut_redirection_cmd(char *command);
char *set_name(char *command);
char *set_val(char *command);
char *read_stdin(char *end_word);
char *str_dup(char *str);

env_t *move_beginning(env_t *list);
env_t *move_end(env_t *list);
env_t *transform_env(char **envp);

int count_spaces(char *str);
int comp_str(char *str1, char *str2);
int exit_command(char *command, env_t **env_list);
int get_command(char *command, env_t **envp);
int pipe_cmd(char *command, env_t **env_list);
int redirection_cmd(char *command, env_t **env_list);
int my_getnbr(char *str);
int is_root(env_t **env_list);
int list_len(env_t *list);
int minishell(env_t **envp);
int str_len(char *str);
int tab_len(char **tab);
int find_list_len(read_t *list);

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
void write_command(char *command, char **cmd, env_t **env_list);
void read_command(char *command, char **cmd, env_t **env_list);
void multiple_cmd(char *command, env_t **env_list);
void get_specific_command(char *command, int *pipe, int *redirect,
int *multiple);

#endif /* !minishell */
