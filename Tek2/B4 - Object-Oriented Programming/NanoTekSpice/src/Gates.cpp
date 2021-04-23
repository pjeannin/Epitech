/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Gates
*/

#include "../include/Gates.hpp"

namespace nts {
    Tristate Gates::norGate(Tristate a, Tristate b)
    {
        if (a == TRUE && b == TRUE)
            return (TRUE);
        if ((a == TRUE && b == UNDEFINED) || (a == UNDEFINED && b == TRUE))
            return (UNDEFINED);

        return (FALSE);
    }

    Tristate Gates::nandGate(Tristate a, Tristate b)
    {
        if (a == TRUE && b == TRUE)
            return (FALSE);
        if ((a == TRUE && b == UNDEFINED) || (a == UNDEFINED && b == TRUE))
            return (UNDEFINED);

        return (TRUE);
    }

    Tristate Gates::xorGate(Tristate a, Tristate b)
    {
        if ((a == TRUE && b == FALSE) || (a == FALSE && b == TRUE))
            return (TRUE);
        if (a == UNDEFINED || b == UNDEFINED)
            return (UNDEFINED);

        return (FALSE);
    }

    Tristate Gates::orGate(Tristate a, Tristate b)
    {
        if (a == TRUE || b == TRUE)
            return (TRUE);
        if (a == UNDEFINED || b == UNDEFINED)
            return (UNDEFINED);

        return (FALSE);
    }

    Tristate Gates::andGate(Tristate a, Tristate b)
    {
        if (a == TRUE && b == TRUE)
            return (TRUE);
        if (a == FALSE || b == FALSE)
            return (FALSE);

        return (UNDEFINED);
    }

    Tristate Gates::inverterGate(Tristate a)
    {
        if (a == TRUE)
            return (FALSE);
        if (a == FALSE)
            return (TRUE);

        return (UNDEFINED);
    }
}
