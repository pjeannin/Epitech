/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** match CPool project
*/

int test(char const *s1, char const *s2, int i, int res)
{
    int j = 0;
    int k;
    //int res = 0;

    while (s2[i] == '*' && s2[i] != '\0')
        ++i;
    ++i;
    while (s2[i] != s1[j] && s1[j] != '\0')
        ++j;
    while (s2[i] == s1[j] && s2[i] != '\0' && s1[j] != '\0') {
        ++i;
        ++j;
        res = 1;
    }
    if (s2[i] == '\0' && s1[j] == '\0')
        return (res);
    if (s2[i] == '*' && s2[i + 1] == '\0')
        return (1);
    if (s2[i] == '*')
        return (8);
    return (0);
}

int match(char const *s1, char const *s2)
{
    int res = 8;
    int i = 0;

    if (s2[0] != '*' && s2[0] != s1[0])
        return (0);
    res = test(s1, s2, i, res);
    while (res == 8) {
        if (s2[i] == '*' && s2[i + 1] == '\0')
            return (1);
        res = test(s1, s2, i, res);
        ++i;
    }
    return (res);
}

int main (int argc, char **argv)
{
    int t = 48;

    t += match(argv[1], argv[2]);
    write(1, &t, 1);
}