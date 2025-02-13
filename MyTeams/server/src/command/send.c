/*
** EPITECH PROJECT, 2024
** teams
** File description:
** send
*/

#include <string.h>
#include <malloc.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"
#include "../libs/myteams/logging_server.h"

static bool is_receiver_connected(connected_t *client, char **array, size_t *i)
{
    for (; *i < MAX_CONNECTED_CLIENT; (*i)++) {
        if (client[*i].fd == UNKNOW) {
            continue;
        }
        if (strcmp(client[*i].user_uuid, array[1]) == 0) {
            return true;
        }
    }
    return false;
}

static void send_send_success(connected_t *client, char *sender, char **array)
{
    size_t i = 0;
    char reply[MAX_BUFFER_SIZE];
    bool found = is_receiver_connected(client, array, &i);

    if (found == false) {
        return;
    }
    strcpy(reply, SEND_RECEIVER_OK);
    strcat(reply, "\"");
    strcat(reply, sender);
    strcat(reply, "\" \"");
    strcat(reply, array[2]);
    strcat(reply, "\"\r\n");
    send_to_client(client[i], reply);
}

static void sender(connected_t *c, char **a, users_data_t *s, users_data_t *r)
{
    send_send_success(c, s->uuid, a);
    server_event_private_message_sended(s->uuid, r->uuid, a[2]);
}

static void set_uuid(direct_message_t **dm, char **a, users_data_t *d, int who)
{
    if (who == 0)
        (*dm)->receiver_uuid = strdup(a[1]);
    else
        (*dm)->receiver_uuid = strdup(d->uuid);
}

static bool init_dm(ll_t **list, char **array, users_data_t *data, int who)
{
    direct_message_t *dm = NULL;
    messages_t *message = NULL;

    *list = init_json(NULL, EMPTY);
    (*list)->index = 0;
    (*list)->type = DIRECT_MESSAGE;
    dm = malloc(sizeof(direct_message_t));
    set_uuid(&dm, array, data, who);
    dm->messages = init_json(NULL, EMPTY);
    dm->messages->index = 0;
    dm->messages->type = MESSAGES;
    message = malloc(sizeof(messages_t));
    message->msg = strdup(array[2]);
    message->sender_uuid = strdup(data->uuid);
    message->sent_time = get_time();
    message->sent_time_str = time_to_string(message->sent_time);
    dm->messages->data = message;
    (*list)->data = dm;
    return true;
}

static void add_message(ll_t **list, char **array, users_data_t *sender_data)
{
    messages_t *message = malloc(sizeof(messages_t));

    message->msg = strdup(array[2]);
    message->sender_uuid = strdup(sender_data->uuid);
    message->sent_time = get_time();
    message->sent_time_str = time_to_string(message->sent_time);
    append_messages(*list, message);
}

static direct_message_t *define_dm(ll_t **l, char **a, users_data_t *s, int w)
{
    direct_message_t *dm = NULL;

    if (w == 0) {
        dm = finder(*l, a[1], false);
    } else {
        dm = finder(*l, s->uuid, false);
    }
    return dm;
}

static void push_values(ll_t **l, char **array, users_data_t *sender, int who)
{
    direct_message_t *dm = define_dm(l, array, sender, who);
    messages_t *message = NULL;

    if (dm == NULL) {
        dm = malloc(sizeof(direct_message_t));
        if (who == 0)
            dm->receiver_uuid = strdup(array[1]);
        else
            dm->receiver_uuid = strdup(sender->uuid);
        message = malloc(sizeof(messages_t));
        message->msg = strdup(array[2]);
        message->sender_uuid = strdup(sender->uuid);
        message->sent_time = get_time();
        message->sent_time_str = time_to_string(message->sent_time);
        dm->messages = init_json(message, MESSAGES);
        dm->messages->index = 0;
        append_direct_message(*l, dm);
    } else {
        add_message(&dm->messages, array, sender);
    }
}

static void handle_send(connected_t *cli, ll_t **list, char **array, int got)
{
    users_data_t *sender_data = finder(*list, cli[got].user_uuid, false);
    users_data_t *receiver_data = finder(*list, array[1], false);
    bool filled_sender = false;
    bool filled_receiver = false;

    if (receiver_data == NULL || strcmp(sender_data->uuid, array[1]) == 0)
        return send_client_uuid_error(cli[got], array[1]);
    if (sender_data->dm == NULL)
        filled_sender = init_dm(&sender_data->dm, array, sender_data, 0);
    if (receiver_data->dm == NULL)
        filled_receiver = init_dm(&receiver_data->dm, array, sender_data, 1);
    if (filled_sender == false)
        push_values(&sender_data->dm, array, sender_data, 0);
    if (filled_receiver == false)
        push_values(&receiver_data->dm, array, sender_data, 1);
    sender(cli, array, sender_data, receiver_data);
    send_to_client(cli[got], SEND_SENDER_OK);
}

void send_msg(connected_t *client, server_t *server, char **arr, int got)
{
    size_t len = count_array_length(arr);

    if (client[got].is_login == false) {
        return send_to_client(client[got], NOT_CONNECTED);
    }
    if (len < 3) {
        return send_to_client(client[got], PARAMETER_TOO_LOW);
    }
    if (len > 3) {
        return send_to_client(client[got], TOO_MANY_PARAMETER);
    }
    if (strlen(arr[1]) > MAX_UUID_LENGTH || strlen(arr[2]) > MAX_BODY_LENGTH) {
        return send_to_client(client[got], PARAMETER_TOO_LONG);
    }
    handle_send(client, &server->users, arr, got);
}
