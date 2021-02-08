/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

typedef union
{
    struct
    {
        uint16_t foo;
        union
        {
            uint16_t bar;
            uint16_t foo;
        } bar;
    } foo;
    uint32_t bar;
} foo_t;

#endif /* !EX05_H_ */
