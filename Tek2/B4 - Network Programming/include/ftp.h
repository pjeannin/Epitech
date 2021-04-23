/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** ftp
*/

#ifndef FTP_H_
#define FTP_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SUCCESS         0
#define FAILURE         84
#define RETURN_FAILURE  1
#define RETURN_SUCCESS  0
#define LOGGEDOUT       -1
#define ONLYUSERNAME    0
#define LOGGEDIN        1
#define STATUS_NO       -1
#define STATUS_PORT     10
#define STATUS_PASV     20
#define USER            "Specify user for authentication"
#define PASS            "Specify password for authentication"
#define CWD             "Change working directory"
#define CDUP            "Change working directory to parent directory"
#define QUIT            "Disconnection"
#define DELE            "Delete file on the server"
#define PWD             "Print working directory"
#define PASV            "Enable \"passive\" mode for data transfer"
#define PORT            "Enable \"active\" mode for data transfer"
#define HELP            "List available commands"
#define NOOP            "Do nothing"
#define RETR            "Download file from server to client"
#define STOR            "Upload file from client to server"
#define LIST            "List files in the current working directory"
#define MAX_CLIENT      15

typedef struct server_s {
    int server_fd;
    int client_fd;
    int port;
    char *path;
    struct sockaddr_in sock_in;
    socklen_t sock_size;
} server_t;

typedef struct client_s {
    int fd;
    char *ip;
    char *password;
    char *username;
    int is_logged_in;
    int quit;
    int port_pasv_fd;
    int pasv_port;
    int port_pasv_mode;
} client_t;

int helper(int argc, char **argv);
int error_handling(int argc, char **argv);
int ftp(int port, char *starting_directory);
int init_ftp_server(server_t *server, int port, char *statring_directory);
int run_server(server_t *server);
void accepted_client(server_t *server, char *ip_adress, client_t **clients);
char *get_line(int fd);
void interpret_command(char **command, client_t *client);
void free_tab(char **tab);
int tab_len(char **tab);
client_t *new_client(server_t *server, char *ip_adress);
char **split_string(char *str, char *tok);
void display_error(client_t *client, char *error);
char *get_ip_from_tab(char **tab);
client_t **create_empty_client_tab(void);
int init_data_transfer_connection(client_t *client);

// Server commands

void cdup(char **command, client_t *client);
void cwd(char **command, client_t *client);
void dele(char **command, client_t *client);
void help(char **command, client_t *client);
void list(char **command, client_t *client);
void noop(char **command, client_t *client);
void pass(char **command, client_t *client);
void pasv(char **command, client_t *client);
void port(char **command, client_t *client);
void pwd(char **command, client_t *client);
void quit(char **command, client_t *client);
void retr(char **command, client_t *client);
void stor(char **command, client_t *client);
void user(char **command, client_t *client);

#endif /* !FTP_H_ */
