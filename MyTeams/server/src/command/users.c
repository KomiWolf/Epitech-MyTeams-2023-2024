/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** users
*/

#include <string.h>

#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

static bool is_user_connected(connected_t *client, char *name)
{
    for (size_t i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].fd == UNKNOW) {
            continue;
        }
        if (strcmp(client[i].user_name, name) == 0) {
            return true;
        }
    }
    return false;
}

static void fetch_users_data(connected_t *client, ll_t *users_list, int got)
{
    users_data_t *user_data = NULL;
    char reply[MAX_BUFFER_SIZE];

    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, USERS_OK);
    for (; users_list != NULL; users_list = users_list->next) {
        user_data = users_list->data;
        strcat(reply, "\"new_user\" \"");
        strcat(reply, user_data->uuid);
        strcat(reply, "\" \"");
        strcat(reply, user_data->name);
        strcat(reply, "\" \"");
        if (is_user_connected(client, user_data->name) == true) {
            strcat(reply, "on\" ");
        } else {
            strcat(reply, "off\" ");
        }
    }
    strcat(reply, "\r\n");
    send_to_client(client[got], reply);
}

void users(connected_t *client, server_t *server, char **array, int got)
{
    size_t len = count_array_length(array);
    ll_t *users_list = server->users;

    if (client[got].is_login == false) {
        send_to_client(client[got], NOT_CONNECTED);
        return;
    }
    if (len > 1) {
        send_to_client(client[got], TOO_MANY_PARAMETER);
        return;
    }
    if (users_list->type == EMPTY) {
        send_to_client(client[got], INTERNAL_SERVER_ERROR);
        return;
    }
    fetch_users_data(client, server->users, got);
}
