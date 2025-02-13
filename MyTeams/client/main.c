/*
** EPITECH PROJECT, 2024
** teams
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "client/client.h"
#include "constants.h"
#include "client/client.h"

static int display_helper(void)
{
    puts("USAGE: ./myteams_cli ip port\n");
    puts("\tip\tis the server ip address on which the server socket listens");
    puts("\tport\tis the port number on which the server socket listens");
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac == 2 &&
    (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0)) {
        return display_helper();
    }
    if (handle_client_error(ac, av) == FUNC_ERROR) {
        return ERROR;
    }
    if (start_client(av[1], atoi(av[2])) == FUNC_ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
