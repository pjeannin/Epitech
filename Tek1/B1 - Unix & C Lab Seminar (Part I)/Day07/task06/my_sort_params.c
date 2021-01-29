/*
** EPITECH PROJECT, 2019
** my_sort_params.c
** File description:
** sort params
*/

int main (int argc, char **argv)
{
    char *tmp;
    int count = 0;

    for (int k = 0; k < argc; ++k) {
        count = argc - 1;
        while (count > 1) {
            if (my_strcmp(argv[count],argv[count - 1]) < 0) {
                tmp = argv[count];
                argv[count] = argv[count - 1];
                argv[count - 1] = tmp;
            }
            --count;
        }
    }
    --count;
    while (count < argc) {
        my_putstr(argv[count]);
        my_putchar('\n');
        ++count;
    }
    return (0);
}
