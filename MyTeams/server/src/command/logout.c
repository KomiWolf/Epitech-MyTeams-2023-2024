/*
** EPITECH PROJECT, 2024
** teams
** File description:
** logout
*/

#include <string.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"
#include "../libs/myteams/logging_server.h"

static void send_logout_success(connected_t client)
{
    char reply[MAX_BUFFER_SIZE];

    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, LOGOUT_OK);
    strcat(reply, "\"");
    if (client.user_uuid != NULL) {
        strcat(reply, client.user_uuid);
    }
    strcat(reply, "\" \"");
    if (client.user_name != NULL) {
        strcat(reply, client.user_name);
    }
    strcat(reply, "\"\r\n");
    server_event_user_logged_out(client.user_uuid);
    send_to_client(client, reply);
}

void logout(connected_t *client, server_t *server, char **array, int got)
{
    size_t len = count_array_length(array);

    if (len > 1) {
        send_to_client(client[got], TOO_MANY_PARAMETER);
        return;
    }
    send_logout_success(client[got]);
    FD_CLR(client[got].fd, &server->current_fd);
    delete_client(client, client[got].fd);
}
