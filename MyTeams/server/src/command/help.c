/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** help
*/

#include <string.h>

#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

void help(connected_t *client, char **array, int got)
{
    char reply[MAX_BUFFER_SIZE];
    size_t len = count_array_length(array);

    if (client[got].is_login == false) {
        send_to_client(client[got], NOT_CONNECTED);
        return;
    }
    if (len > 1) {
        send_to_client(client[got], TOO_MANY_PARAMETER);
        return;
    }
    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, HELP_OK);
    strcat(reply, "/help, /login, /logout, /users, /user, /send, /messages\"");
    strcat(reply, "\r\n");
    send_to_client(client[got], reply);
}
