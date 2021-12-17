##
## EPITECH PROJECT, 2021
## B-NWP-400-STG-4-1-myftp-pierre.jeannin
## File description:
## Makefile
##

CXX = gcc

CFLAGS = #options de compilation

LDFLAGS = #options de link

SRC = 	src/main.c							\
		src/helper.c						\
		src/error_handling.c				\
		src/ftp.c							\
		src/init_ftp_server.c				\
		src/run_server.c					\
		src/accepted_client.c				\
		src/get_line.c						\
		src/interpret_command.c				\
		src/new_client.c					\
		src/split_string.c					\
		src/display_error.c					\
		src/get_ip_from_tab.c				\
		src/create_empty_client_tab.c 		\
		src/init_data_transfer_connection.c	\
		src/commands/cdup.c					\
		src/commands/cwd.c					\
		src/commands/dele.c					\
		src/commands/list.c					\
		src/commands/noop.c					\
		src/commands/pass.c					\
		src/commands/pasv.c					\
		src/commands/port.c					\
		src/commands/pwd.c					\
		src/commands/quit.c					\
		src/commands/retr.c					\
		src/commands/stor.c					\
		src/commands/help.c					\
		src/commands/user.c

OBJ = $(SRC:.c=.o)

OUTPUT = myftp #nom de l'exectutable

all: $(OBJ)
	@$(CXX) $(LDFLAGS) -o $(OUTPUT) $^
	@echo "Compilation ended"

$(OBJ): %.o: %.c
	@$(CXX) $(CFLAGS) -Iinclude -c $< -o $@
	@echo "$@ Creation"

clean:
	@rm -rf src/*.o
	@rm -rf src/commands/*.o
	@echo "Clean"

fclean: clean
	@rm -rf $(OUTPUT)
	@echo "Fclean"

re: fclean all

run: all
	@echo "start FTP server"
	@./$(OUTPUT) 20 server