##
## EPITECH PROJECT, 2021
## B-ASM-400-STG-4-1-asmminilibc-pierre.jeannin
## File description:
## Makefile
##

SRC		=	src/strlen.asm	\
			src/memcpy.asm

AS		=	nasm

CC		=	gcc

OBJ		=	$(SRC:.asm=.o)

ASFLAGS	=	-f elf64 -Wall -Ox

NAME	=	libasm.so

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -nostdlib -shared -fPIC $(OBJ) -o $(NAME)

%.o : %.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:		fclean all