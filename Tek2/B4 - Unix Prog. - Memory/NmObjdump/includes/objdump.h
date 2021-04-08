/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-nmobjdump-pierre.jeannin
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include "flags.h"

int check_input(int argc, char **argv);
int run_objdump(char *filepath);
Elf64_Ehdr *get_struct(char *filepath, void **buf);
int check_magic(unsigned char *magic);
void objdump_f(Elf64_Ehdr *elf, char *filepath);
unsigned int get_flags(Elf64_Ehdr *elf);
void print_flags(unsigned int flags);
char *get_architechture(int e_machine);
void objdump_s(Elf64_Ehdr *elf, void *buf);
void print_sections(Elf64_Shdr *shdr, char *str_tab, int shNum, uint8_t *data);
int is_printable(char c);
void print_section(Elf64_Shdr *shdr, char *str_tab, uint8_t *data, int i);
void print_space(unsigned int index, char end);
void print_hexadecimal(Elf64_Shdr shdr, char *buffer, unsigned int index);

#endif /* !OBJDUMP_H_ */
