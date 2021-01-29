/*
** EPITECH PROJECT, 2019
** Rush 2 find langage
** File description:
** find langage
*/

void recognize (char *str, int *count_f, int *count_e)
{
    struct letter current[26];

    for (int i = 97; i <= 122; ++i) {
        current[i - 97].letter = i;
        current[i - 97].freq = compute_freq_bis(str, nbr_letter_bis(str, i));
    }
    
    for (int i = 0; i <= 26; ++i) {
        if (ABS((french[i].freq - current[i].freq)) <= 0.2)
            ++*count_f;
        if (ABS((english[i].freq - current[i].freq)) <= 0.2) 
            ++*count_e;
        }
}