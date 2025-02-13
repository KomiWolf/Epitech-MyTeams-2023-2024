/*
** EPITECH PROJECT, 2024
** teams
** File description:
** send_to_client
*/

#include <unistd.h>
#include <string.h>

#include "server/server.h"

void send_to_client(connected_t client, const char *msg)
{
    write(client.fd, msg, strlen(msg));
}
