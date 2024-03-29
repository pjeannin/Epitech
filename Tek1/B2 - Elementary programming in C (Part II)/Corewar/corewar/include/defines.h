/*
** EPITECH PROJECT, 2020
** define.h
** File description:
** header file for the defines
*/

#ifndef DEFINES_H_
#define DEFINES_H_

/*   Redirects */

/*   Values    */

/*   Macros    */

/*  Help  */

#define HELP "USAGE :\n" \
    "   ./corewar [-dump nbr_cycle] " \
    "[[-n prog_number] [-a load_address] prog_name] ...\n" \
    "\nDESCRIPTION\n" \
    "   -dump nbr_cycle     dumps the memory after the" \
    " nbr_cycle execution (if the round isn’t" \
    "already over) with the following format: 32 bytes/line in" \
    "hexadecimal (A0BCDEFE1DD3...)\n" \
    "   -n prog_number      sets the next program’s number. By default," \
    " the first free number" \
    "in the parameter order\n" \
    "   -a load_address     sets the next program’s loading address." \
    " When no address is" \
    "specified, optimize the addresses so that the processes are as far" \
    "away from each other as possible. The addresses are MEM_SIZE modulo\n" \

#endif /* DEFINES_H_ */
