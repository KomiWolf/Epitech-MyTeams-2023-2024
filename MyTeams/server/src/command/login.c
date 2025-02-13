/*
** EPITECH PROJECT, 2024
** teams
** File description:
** login
*/

#include <string.h>
#include <malloc.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"
#include "../libs/myteams/logging_server.h"

static users_data_t *fill_user(char *data)
{
    users_data_t *user = malloc(sizeof(users_data_t));

    user->dm = NULL;
    user->teams_uuid = NULL;
    user->name = strdup(data);
    if (user->name == NULL) {
        return NULL;
    }
    user->uuid = generate_uuid();
    if (user->uuid == NULL) {
        return NULL;
    }
    user->dm = NULL;
    user->teams_uuid = NULL;
    return user;
}

static users_data_t *create_user(server_t *server, char *data)
{
    users_data_t *user = fill_user(data);

    if (user == NULL) {
        return NULL;
    }
    if (server->users->data == NULL) {
        server->users->type = USERS;
        server->users->data = user;
        server->users->index = 0;
    } else {
        if (append_users_data(server->users, user) == ERROR) {
            free(user->name);
            free(user->uuid);
            free(user);
            return NULL;
        }
    }
    server_event_user_created(user->uuid, user->name);
    return user;
}

static void send_login_success(connected_t client)
{
    char reply[MAX_BUFFER_SIZE];

    strcpy(reply, LOGIN_OK);
    strcat(reply, "\"");
    strcat(reply, client.user_uuid);
    strcat(reply, "\" \"");
    strcat(reply, client.user_name);
    strcat(reply, "\"\r\n");
    send_to_client(client, reply);
}

static void check_if_user_exist(connected_t *c, server_t *s, char *data, int g)
{
    users_data_t *user = NULL;

    user = finder(s->users, data, true);
    if (user == NULL) {
        user = create_user(s, data);
        if (user == NULL) {
            send_to_client(c[g], INTERNAL_SERVER_ERROR);
            return;
        }
    }
    c[g].is_login = true;
    c[g].user_uuid = strdup(user->uuid);
    c[g].user_name = strdup(user->name);
    server_event_user_logged_in(c[g].user_uuid);
    send_login_success(c[g]);
}

static bool is_user_connected(connected_t *client, char *data, int got)
{
    if (client[got].is_login == true) {
        return true;
    }
    for (size_t i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].user_name == NULL) {
            continue;
        }
        if (strcmp(client[i].user_name, data) == 0) {
            return true;
        }
    }
    return false;
}

void login(connected_t *client, server_t *server, char **array, int got)
{
    size_t len = count_array_length(array);

    if (len == 1) {
        send_to_client(client[got], PARAMETER_TOO_LOW);
        return;
    }
    if (len > 2) {
        send_to_client(client[got], TOO_MANY_PARAMETER);
        return;
    }
    if (strlen(array[1]) > MAX_NAME_LENGTH) {
        send_to_client(client[got], PARAMETER_TOO_LONG);
        return;
    }
    if (is_user_connected(client, array[1], got) == true) {
        send_to_client(client[got], ALREADY_LOGGED);
        return;
    }
    check_if_user_exist(client, server, array[1], got);
}
