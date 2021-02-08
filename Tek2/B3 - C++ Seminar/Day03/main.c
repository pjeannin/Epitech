/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "string.h"

int main(void)
{
    string_t s;
    string_t s2;
    char *tmp = malloc(sizeof(char) * 3);
    char **tab = NULL;
    string_t **stab;

    string_init(&s2, "Salut");
    string_init(&s, "Hello World");
    printf("Should be (Hello World) : (%s)\n", s.str);
    s.assign_s(&s, &s2);
    printf("Should be (Salut) : (%s)\n", s.str);
    s.append_c(&s, " toi !");
    printf("Should be (Salut toi !) : (%s)\n", s.str);
    printf("Should be (a) : (%c)\n", s.at(&s, 1));
    s2.clear(&s2);
    printf("Should be () : (%s)\n", s2.str);
    printf("Should be (11) : (%d)\n", s.size(&s));
    s2.assign_c(&s2, "Bonjour");
    printf("Should be (%d) : (%d)\n", strcmp(s.str, s2.str), s.compare_s(&s, &s2));
    printf("Should be (1) : (%lu)\nShould be (n) : (%s)\n", s2.copy(&s2, tmp, 1, 2), tmp);
    printf("Should be (%s) : (%s)\n", s2.str, s2.c_str(&s2));
    s2.clear(&s2);
    printf("Should be (0) : (%d)\nShould be (1) : (%d)\n", s.empty(&s), s2.empty(&s2));
    s2.assign_c(&s2, "Bonjour");
    printf("Should be (4) : (%d)\n", s2.find_c(&s2, "o", 2));
    printf("Should be (-1) : (%d)\n", s2.find_c(&s2, "x", 2));
    printf("Should be (-1) : (%d)\n", s2.find_c(&s2, "b", 2));
    s2.insert_c(&s2, 3, "blabla");
    printf("Should be (Bonblablajour) : (%s)\n", s2.str);
    s2.insert_c(&s2, 54, "blabla");
    printf("Should be (Bonblablajourblabla) : (%s)\n", s2.str);
    s.insert_s(&s, 58, &s2);
    printf("Should be (Salut toi !Bonblablajourblabla) : (%s)\n", s.str);
    s.assign_c(&s, "5679");
    printf("Should be (5679) : (%d)\n", s.to_int(&s));
    s.assign_c(&s, "je||la.");
    tab = s.split_c(&s, '|');
    printf("Should be \n(je\n\nla.\n)\n(");
    for (int i = 0; tab[i]; ++i)
        printf("%s\n", tab[i]);
    printf(")\n");
    stab = s.split_s(&s, '|');
    printf("Should be \n(je\nsuis\nla.\n)\n(");
    for (int i = 0; stab[i]; ++i)
        printf("%s\n", stab[i]->str);
    printf(")\n");
    string_destroy(&s);
    string_destroy(&s2);
    for (int i = 0; i < 3; ++i) {
        free(tab[i]);
        free(stab[i]);
    }
    free(tab);
    free(stab);

    return (0);
}