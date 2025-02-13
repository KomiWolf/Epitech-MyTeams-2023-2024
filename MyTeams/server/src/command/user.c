/*
** EPITECH PROJECT, 2024
** teams
** File description:
** user
*/

#include <string.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

static void send_user_success(connected_t cli, users_data_t *data, int status)
{
    char reply[MAX_BUFFER_SIZE];

    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, USER_OK);
    strcat(reply, "\"");
    strcat(reply, data->uuid);
    strcat(reply, "\" \"");
    strcat(reply, data->name);
    strcat(reply, "\" \"");
    if (status == CONNECTED_STATUS) {
        strcat(reply, "on");
    } else {
        strcat(reply, "off");
    }
    strcat(reply, "\"\r\n");
    send_to_client(cli, reply);
}

static void handle_user(connected_t *cli, ll_t *users_list, char *data, int g)
{
    users_data_t *user_data = finder(users_list, data, false);
    int user_status = UNKNOW;

    if (user_data == NULL) {
        send_client_uuid_error(cli[g], data);
        return;
    }
    for (size_t i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (cli[i].fd == UNKNOW) {
            continue;
        }
        if (strcmp(data, cli[i].user_uuid) == 0) {
            user_status = CONNECTED_STATUS;
            break;
        }
    }
    send_user_success(cli[g], user_data, user_status);
}

void user(connected_t *client, server_t *server, char **array, int got)
{
    size_t len = count_array_length(array);
    ll_t *users_list = server->users;

    if (client[got].is_login == false) {
        send_to_client(client[got], NOT_CONNECTED);
        return;
    }
    if (len == 1) {
        send_to_client(client[got], PARAMETER_TOO_LOW);
        return;
    }
    if (len > 2) {
        send_to_client(client[got], TOO_MANY_PARAMETER);
        return;
    }
    if (strlen(array[1]) > MAX_UUID_LENGTH) {
        send_to_client(client[got], PARAMETER_TOO_LONG);
        return;
    }
    handle_user(client, users_list, array[1], got);
}
