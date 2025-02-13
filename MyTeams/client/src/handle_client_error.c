/*
** EPITECH PROJECT, 2024
** teams
** File description:
** handle_client_error
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"
#include "json.h"
#include "constants.h"

static int display_error(const char *msg)
{
    puts(msg);
    return FUNC_ERROR;
}

static bool is_ip(const char *ip)
{
    char **ip_array = str_to_word_array(ip, '.');
    int count = 0;

    for (int i = 0; ip_array[i] != NULL; i++) {
        if (is_digit(ip_array[i]) == false) {
            free_string_array(ip_array);
            return false;
        }
        count++;
    }
    if (count != 4) {
        free_string_array(ip_array);
        return false;
    }
    free_string_array(ip_array);
    return true;
}

int handle_client_error(int ac, char **av)
{
    int port = 0;

    if (ac != 3) {
        return display_error(CLIENT_ARGS_NB_ERROR);
    }
    port = atoi(av[2]);
    if (is_ip(av[1]) == false) {
        return display_error(F_ARG_IS_NOT_IP);
    }
    if (is_digit(av[2]) == false) {
        return display_error(S_ARG_IS_NOT_PORT);
    }
    if (port < 1024 || port > 65535) {
        return display_error(S_ARG_IS_NOT_PORT);
    }
    return SUCCESS;
}
