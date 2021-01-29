/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/
#include<stdlib.h>
#define ABS(a)  ((a > 0) ? (a) : (a * (-1)))

struct letter
{
    char letter;
    int occ;
    float freq;
};

struct langage
{
    char letter;
    float freq;
};

const struct langage french[] = {{'a', 7.6}, {'b', 0.9}, {'c', 3.3}, {'d', 3.7},
    {'e', 14.7}, {'f', 1}, {'g', 1}, {'h', 0.7}, {'i', 7.5}, {'j', 0.6},
    {'k', 0.1}, {'l', 5.5}, {'m', 3}, {'n', 7}, {'o', 5.8}, {'p', 2.5},
    {'q', 1.4}, { 'r', 6.7}, {'s', 7.9}, {'t', 7.2}, {'u', 6.3}, {'v', 1.8},
    {'w', 0}, {'x', 0.4}, {'y', 0.1}, {'z', 0.3}};
const struct langage english[] = {{'a', 8.1}, {'b', 1.5}, {'c', 2.8},
    {'d', 4.3}, {'e', 12.7}, {'f', 2.2}, {'g', 2}, {'h', 6.1}, {'i', 7},
    {'j', 0.2}, {'k', 0.8}, {'l', 4}, {'m', 2.4}, {'n', 6.7}, {'o', 7.5},
    {'p', 1.9}, {'q', 0.1}, {'r', 6}, {'s', 6.3}, {'t', 9.1}, {'u', 2.8},
    {'v', 1}, {'w', 2.4}, {'x', 0.1}, {'y', 2}, {'z', 0.1}};
const struct langage german []= {{'a', 6.5}, {'b', 1.9}, {'c', 2.7}, {'d', 5.1},
    {'e', 16.4}, {'f', 1.1}, {'g', 1}, {'h', 4.6}, {'i', 6.6}, {'j', 0.3},
    {'k', 1.4}, {'l', 3.4}, {'m', 2.5}, {'n', 9.8}, {'o', 2.6}, {'p', 0.7},
    {'q', 0}, { 'r', 7}, {'s', 7.3}, {'t', 6.2}, {'u', 4.1}, {'v', 0.8},
    {'w', 1.9}, {'x', 0}, {'y', 0}, {'z', 1.1}};
const struct langage spanish []= {{'a', 11.5}, {'b', 2.2}, {'c', 4}, {'d', 5},
    {'e', 12.2}, {'f', 0.7}, {'g', 1.8}, {'h', 0.7}, {'i', 6.2}, {'j', 0.5},
    {'k', 0}, {'l', 5}, {'m', 3.2}, {'n', 6.7}, {'o', 8.7}, {'p', 2.5},
    {'q', 0.9}, { 'r', 6.9}, {'s', 8}, {'t', 4.6}, {'u', 2.9}, {'v', 1.1},
    {'w', 0}, {'x', 0.2}, {'y', 1}, {'z', 0.5}};

void get_arg(int argc, char **argv, int i)
{
    struct letter current[argc];

    current[i].letter = argv[i][0];
    current[i].occ = nbr_letter(argv[1], current[i].letter);
    current[i].freq = compute_freq(argv[1], argv[i][0], current[i].occ);
}

void recognize (char *str, int *count_f, int *count_e)
{
    struct letter current[26];

    for (int i = 97; i <= 122; ++i) {
        current[i - 97].letter = i;
        current[i - 97].freq = compute_freq_bis(str, nbr_letter_bis(str, i));
    }
    
    for (int i = 0; i <= 26; ++i) {
        if (ABS((french[i].freq - current[i].freq)) <= 0.5)
            ++(*count_f);
        if (ABS((english[i].freq - current[i].freq)) <= 0.5) 
            ++(*count_e);
        }
}

void recognize_bis (char *str, int *count_g, int *count_s)
{
    struct letter current[26];

    for (int i = 97; i <= 122; ++i) {
        current[i - 97].letter = i;
        current[i - 97].freq = compute_freq_bis(str, nbr_letter_bis(str, i));
    }
    for (int i = 0; i <= 26; ++i) {
        if (ABS((german[i].freq - current[i].freq)) <= 0.5)
            ++(*count_g);
        if (ABS((spanish[i].freq - current[i].freq)) <= 0.5)
            ++(*count_s);
    }
}

int main (int argc, char **argv)
{
    int count_g;
    int count_s;
    int count_f;
    int count_e;
    int *g = &count_g;
    int *s = &count_s;
    int *f = &count_f;
    int *e = &count_e;
    int error;

    error = err(argc, argv);
    if (error == 84)
        return (84);
    for (int i = 2; i < argc; ++i) {
        get_arg(argc, argv, i);
    }
    recognize(argv[1], f, e);
    recognize_bis(argv[1], g, s);
    dis_res(g, s, f, e);
    return (0);
}
