/*
** EPITECH PROJECT, 2024
** teams
** File description:
** send_uuid_error
*/

#include <string.h>

#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

void send_client_uuid_error(connected_t client, char *data)
{
    char reply[MAX_BUFFER_SIZE];

    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, USER_UUID_ERROR);
    strcat(reply, "\"");
    strcat(reply, data);
    strcat(reply, "\"\r\n");
    send_to_client(client, reply);
}
