/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_printf
*/

#include <stdio.h>
int my_printf(char *, ...);

int	main(int ac, char **av)
{
    int	ret[2];
    char	str[] = "astek";
    char	stre[] = {'a', 's', 10, 'e', 'k', 0};
    char    stra[] = {'a', 's', 30, 'e', 'k', 0};

    printf("##### Tests simple #####\n");
    printf(   "0) Modulo [%%] : {%%}\n");
    my_printf("=> Modulo [%%] : {%%}\n");
    printf(   "1) Nombre signe [d] : {%d}\n", 6);
    my_printf("=> Nombre signe [d] : {%d}\n", 6);
    printf(   "2) Nombre signe [i] : {%i}\n", 42);
    my_printf("=> Nombre signe [i] : {%i}\n", 42);
    printf(   "3) Nombre octal [o] : {%o}\n", 3456789);
    my_printf("=> Nombre octal [o] : {%o}\n", 3456789);
    printf(   "4) Nombre non signe [u] : {%u}\n", -42);
    my_printf("=> Nombre non signe [u] : {%u}\n", -42);
    printf(   "5) Nombre hexadecimal [x] : {%x}\n", 3456789);
    my_printf("=> Nombre hexadecimal [x] : {%x}\n", 3456789);
    printf(   "6) Nombre hexadecimal [X] : {%X}\n", 3456789);
    my_printf("=> Nombre hexadecimal [X] : {%X}\n", 3456789);
    printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
    my_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
    printf(   "8) Caractere [c] : {%c}\n", 42);
    my_printf("=> Caractere [c] : {%c}\n", 42);
    printf(   "9) Chaine [s] : {%s}\n", str);
    my_printf("=> Chaine [s] : {%s}\n", str);
    printf(   "10) Chaine etendue [S] : as\\012ek\n");
    my_printf("=>  Chaine etendue [S] : %S\n", stre);
    printf(   "11) Pointeur [p] : {%p}\n", str);
    my_printf("=>  Pointeur [p] : {%p}\n", str);
    printf(   "12) Mauvais parametre [k] : {%k}\n", 42);
    my_printf("=>  Mauvais parametre [k] : {%k}\n", 42);
    printf("Appuyez sur [entree] pour continuer...\n");
    getchar();
    printf("\n##### Tests pour verifier #####\n");
    printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
    my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
    printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
    my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
    printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
    my_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
    printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 45678, str, 42);
    my_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 45678, str, 42);
    printf(   "5) Affichage multiple [s S X] : {%s} {as\\012ek} {%X}\n", str, -7);
    my_printf("=> Affichage multiple [s S X] : {%s} {%S} {%X}\n", str, stre, -7);
    printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d\n", 1, 2, 3, 4, 5);
    my_printf("=> Affichage long [d d d ...] : %d %d %d %d %d\n", 1, 2, 3, 4, 5);
    printf(   "6) Affichage long [s S s ...] : %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\036ek %s as\\036ek\n", str, str, str, str, str, str);
    my_printf("=> Affichage long [s S s ...] : %s %S %s %S %s %S %s %S %s %S %s %S\n", str, stre, str, stre, str, stre, str, stre, str, stra, str, stra);
    printf("Appuyez sur une touche pour continuer...\n");
    getchar();
    printf("\n##### Formatage simpe #####\n");
    printf(   "1) Formatage simple [#d] : {%#d}\n", 42);
    my_printf("=> Formatage simple [#d] : {%#d}\n", 42);
    printf(   "2) Formatage simple [#x] : {%#x}\n", 0x12345);
    my_printf("=> Formatage simple [#x] : {%#x}\n", 0x12345);
    printf(   "3) Formatage simple [#o] : {%#o}\n", 012345);
    my_printf("=> Formatage simple [#o] : {%#o}\n", 012345);
    printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
    my_printf("=> Formatage simple [0d] : {%0d}\n", 42);
    printf(   "5) Formatage simple [10d] : {%10d}\n", 42);
    my_printf("=> Formatage simple [10d] : {%10d}\n", 42);
    printf(   "6) Formatage simple [ d] : {% d}\n", 42);
    my_printf("=> Formatage simple [ d] : {% d}\n", 42);
    printf(   "6) Formatage simple [ d] : {% d}\n", -42);
    my_printf("=> Formatage simple [ d] : {% d}\n", -42);
    printf(   "7) Formatage simple [-d] : {%-d}\n", 42);
    my_printf("=> Formatage simple [-d] : {%-d}\n", 42);
    printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
    my_printf("=> Formatage simple [+d] : {%+d}\n", 42);
    printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
    my_printf("=> Formatage simple [+d] : {%+d}\n", -42);
    // printf("Appuyez sur une touche pour continuer...\n");
    // getchar();
    // printf("\n##### Formatage complexe #####\n");
//     printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
//     my_printf("=>  Formatage multiple [ 5d] : {% 5d}\n", 42);
//     printf(   "11) Formatage multiple [-32o] : {%-32o}\n", 012345);
//     my_printf("=>  Formatage multiple [-32o] : {%-32o}\n", 012345);
//     printf(   "12) Formatage multiple [-10+d] : {%+-10d}\n", 12345);
//     my_printf("=>  Formatage multiple [-10+d] : {%-10+d}\n", 12345);
//     printf(   "13) Formatage compose [-5cP] : %-5cP\n", 42);
//     my_printf("=>  Formatage compose [-5cP] : %-5cP\n", 42);
//     printf(   "14) Formatage compose [-30sP]: %-30sP\n", str);
//     my_printf("=> Formatage compose [-30sP]: %-30sP\n", str);
//     printf(   "15) Formatage compose [-4SP] : as\\012ekP\n");
//     my_printf("=>  Formatage compose [-4SP] : %-4SP\n", stre);
//     printf(   "16) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
//     my_printf("=>  Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
//     printf(   "17) Formatage ultracompose [#15.12b] : {101111101111110000001}\n");
//     my_printf("=>  Formatage ultracompose [#15.12b] : {%#15.12b}\n", 1564545);
//     printf(   "18) Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
//     my_printf("=>  Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
//     printf(   "19) Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
//     my_printf("=>  Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
//     printf(   "20) Formatage pourcent [30%%] : {%30%}\n");
//     my_printf("=>  Formatage pourcent [30%%] : {%30%}\n");
//     printf(   "21) Formatage pourcent [-30pourcent] : {%-30%}\n");
//     my_printf("=>  Formatage pourcent [-30pourcent] : {%-30%}\n");
//     ret[0] = printf(   "22) Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
//     ret[1] = my_printf("=>  Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
//     printf(   "23) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
//     my_printf("=>  Verification de la valeur de retour [d] : {%d}\n", ret[1]);
//     printf(   "24) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
//     my_printf("=>  Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
//     my_printf("Segmentation fault ;)\n");
    return(0);
}