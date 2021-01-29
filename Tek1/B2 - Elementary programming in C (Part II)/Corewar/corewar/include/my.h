/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "libs.h"

#define ISNUM(x) (x >= '0' && x <= '9')
#define ISMIN(x) (x >= 'a' && x <= 'z')
#define ISMAJ(x) (x >= 'A' && x <= 'Z')
#define ISLET(x) (ISMIN(x) || ISMAJ(x))
#define TOMIN(x) ((ISMAJ(x)) ? x + 32 : x)
#define TOMAJ(x) ((ISMIN(x)) ? x - 32 : x)
#define ABS(x) ((x < 0) ? x * -1 : x)

//numbers
int my_atoi(char const *str);
//gets a number in an array
int my_atoie(char const *str);
//gets the number in an array starting by a number
int my_getnbr(char const *str);
//gets the first number of an array if there is
int my_nbrlen(int nb);
//return the number of decial of a number
float my_atof(char const *str);
//gets a float in an array
float my_atofe(char const *str);
//gets the float in an array starting by a float
float my_getfloat(char const *str);
//gets the first float of a string

//length
int my_strlen(char const *str);
//returns the length of the string
int my_char2len(char **char2);
//return the numbers of tabs in the 2darray
int count_words(char *str, char sep);
//counts words in a string

//string manipulation
char *my_strdup(char *str);
//duplicates a string
char *my_strdup_f(char *str);
//duplicates then free
char **my_char2dup(char **array);
//duplicates an array
char *my_strndup(char *str, int n);
//duplicates n characters of a string
char *my_strndup_f(char *str, int n);
//duplicates then free
int my_strcomp(char *string, char *testr);
//returns 1 if two string are identical
char *my_strcat(char *dest, char *src);
//concatenate to a string and free both
char *my_strncat(char *dest, char *src, int size);
//concatenate n characters to a string and free both
char *my_strcat_nf(char *dest, char *src);
//concatenates two strings
char *my_strncat_nf(char *dest, char *src, int n);
//concatenates n characters of a string
char *my_slice(char *str, int start, int end);
//cuts a string
int part_comp(char *str, char *look);
//check if (str) starts by (look)
int my_strfind(char *str, char *look);
//give the position of (look) in (str)
int str_compare(char *str1, char *str2);
//indicate if the string if first in alphabetical order
int contains(char *str, char *checks);
//checks if (str) contains one of (checks)'s characters
char *my_glue_sep(char *path, char *name, char sep);
//concatenate with a separator
int my_revstr(char *str);
//reverses a string
int my_swap(char *a, char *b);
// swaps two value

//writing
int my_putchar(int fd, char c);
//puts a char in the given fd
int my_putstr(int fd, char const *str);
//puts a string in the given fd
int my_putnstr(int fd, char const *str, int n);
//puts n characters of a string in the given fd
int my_puttwostr(int fd, char const *str, char const *str2);
//puts two strings one after the other in the given fd
int my_put2str(int fd, char **arr);
//puts an array of string
int my_printf(int fd, char const *format, ...);
//printf with less functions
//string checking
int my_str_isnum(char const *str);
//checks if the string is numerical return (1) if true
int my_str_isposnum(char const *str);
//checks if the string is positive numerical return (1) if true
int my_str_isalpha(char const *str);
//checks if the string is alphanumerical return (1) if true
int my_str_isfloat(char const *str);
//checks if the string is a float return (1) if true
int my_word_isposnum(char const *str);
//checks if a word is a positive numuber

//special
char *my_int_to_array(int nb);
//transforms an int into an array;
char **parse(char *toparse, char separator);
//parses a string with its given separator
int get_fd(char *name);
//opens a file and returns its fd
char *read_file(int fd, int rdsize);
//read a file an returns it as a string
int find_word(char *line, int which);
//find Xth word

//alloc related
char *my_calloc(int type, int len);
//malloc filling the string with '\0'
int freeif(void *elem);
//free if it exists
int freeif_2d(void **);
//free a 2d array if it exists
void multi_free(char *str, ...);
//frees he things you give him
char **my_malloc_db(int height, int width);
//malloc 2d array
void **my_malloc_type(int height, int width, int size_db, int size);
//malloc double array any type
void my_free_typoo(void **oo);
//free any type of double array

//math
int my_sqr(int nb, int pow);
//squares a number
int my_sqrt(int nb);
//square root of a number

//error
int error(int error, char *str);
// write a error and return error
void *errorn(char *str);
// write an error and return null

#endif /*MY_H_*/
