/*
** EPITECH PROJECT, 2024
** server
** File description:
** handle_server_error
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"
#include "constants.h"

int handle_server_error(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        puts(SERVER_ARGS_NB_ERROR);
        return FUNC_ERROR;
    }
    if (ac == 3 && strcmp(av[2], "--test") != 0) {
        return FUNC_ERROR;
    }
    if (is_digit(av[1]) == false) {
        puts(F_ARG_IS_NOT_PORT);
        return FUNC_ERROR;
    }
    return SUCCESS;
}
