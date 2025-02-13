/*
** EPITECH PROJECT, 2024
** teams
** File description:
** messages
*/

#include <string.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

static void send_messages_success(connected_t client, ll_t *list, char *name)
{
    char reply[MAX_BUFFER_SIZE];
    messages_t *message_data = NULL;

    strcpy(reply, MESSAGES_OK);
    strcat(reply, name);
    strcat(reply, " retrived successfully\" ");
    for (; list != NULL; list = list->next) {
        message_data = list->data;
        strcat(reply, "\"new_message\" \"");
        strcat(reply, message_data->sender_uuid);
        strcat(reply, "\" \"");
        strcat(reply, message_data->sent_time_str);
        strcat(reply, "\" \"");
        strcat(reply, message_data->msg);
        strcat(reply, "\" ");
    }
    strcat(reply, "\r\n");
    send_to_client(client, reply);
}

static void handle_messages(connected_t *cli, ll_t *list, char *str, int got)
{
    users_data_t *my_data = finder(list, cli[got].user_uuid, false);
    users_data_t *other = finder(list, str, false);
    char user_name[MAX_NAME_LENGTH];
    ll_t *dm_list = NULL;
    direct_message_t *dm = NULL;
    ll_t *messages_list = NULL;

    if (other == NULL) {
        return send_client_uuid_error(cli[got], str);
    }
    strcpy(user_name, other->name);
    dm_list = my_data->dm;
    dm = finder(dm_list, str, false);
    if (dm == NULL) {
        return send_client_uuid_error(cli[got], str);
    }
    messages_list = dm->messages;
    send_messages_success(cli[got], messages_list, user_name);
}

void messages(connected_t *client, server_t *server, char **arr, int got)
{
    size_t len = count_array_length(arr);
    ll_t *users_list = server->users;

    if (client[got].is_login == false) {
        return send_to_client(client[got], NOT_CONNECTED);
    }
    if (len < 2) {
        return send_to_client(client[got], PARAMETER_TOO_LOW);
    }
    if (len > 2) {
        return send_to_client(client[got], TOO_MANY_PARAMETER);
    }
    if (strlen(arr[1]) > MAX_UUID_LENGTH) {
        return send_to_client(client[got], PARAMETER_TOO_LONG);
    }
    handle_messages(client, users_list, arr[1], got);
}
