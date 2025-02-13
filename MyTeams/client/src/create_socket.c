/*
** EPITECH PROJECT, 2024
** myTeams
** File description:
** create_socket
*/

#include "client/client.h"

int create_socket(void)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd == -1) {
        printf("Failed to create a socket for the client.\n");
        return FUNC_ERROR;
    }
    return sfd;
}
