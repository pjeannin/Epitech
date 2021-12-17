/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-nmobjdump-pierre.jeannin
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

int check_input(int argc, char **argv);
int run_nm(char *filepath);
Elf64_Ehdr *get_struct(char *filepath, void **buf);
int check_magic(unsigned char *magic);

#endif /* !NM_H_ */
