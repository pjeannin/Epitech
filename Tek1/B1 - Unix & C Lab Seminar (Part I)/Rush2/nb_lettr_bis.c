/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

int nbr_letter_bis(char *str, char letter)
{
    int occurence = 0;
    char letterb;

    if (97 <= letter && letter <= 122)
        letterb = letter - 32;
    if (65 <= letter && letter <= 90)
        letterb = letter +32;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == letter || str[i] == letterb)
            ++occurence;
    }
    return (occurence);
}