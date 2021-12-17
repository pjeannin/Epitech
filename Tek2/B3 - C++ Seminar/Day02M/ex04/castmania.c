/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** castmania
*/

#include "castmania.h"

void display(instruction_type_t instruction_type , void *data)
{
    switch (instruction_type)
        {
        case ADD_OPERATION:
            printf("%d\n", ((addition_t *)((instruction_t *)data)->operation)
            ->add_op.res);
            break;
        case DIV_OPERATION:
            if (((division_t *)((instruction_t *)data)->operation)->div_type ==
            INTEGER)
                printf("%d\n",((integer_op_t*)(((division_t *)
                ((instruction_t *)data)->operation)->div_op))->res);
            else
                printf("%f\n",((decimale_op_t*)(((division_t *)
                ((instruction_t *)data)->operation)->div_op))->res);
            break;
        default:
            break;
        }
}

void exec_operation(instruction_type_t instruction_type , void *data)
{
    void(*instructions[2])(void *) = {exec_add, exec_div};

    if (instruction_type < ADD_OPERATION || instruction_type > DIV_OPERATION)
        return;
    instructions[instruction_type - 2]((void *)(((instruction_t *)data)
    ->operation));
    if (((instruction_t *)data)->output_type == VERBOSE) {
        display(instruction_type, data);
    }
}

void exec_instruction(instruction_type_t instruction_type , void *data)
{
    if (instruction_type < PRINT_INT || instruction_type > DIV_OPERATION)
        return;
    if (instruction_type >= ADD_OPERATION)
        exec_operation(instruction_type, data);
    switch (instruction_type)
    {
    case PRINT_INT:
        printf("%d\n", *((int *)data));
        break;
    case PRINT_FLOAT:
        printf("%f\n", *((float *)data));
        break;
    default:
        break;
    }
}