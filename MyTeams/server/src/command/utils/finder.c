/*
** EPITECH PROJECT, 2024
** teams
** File description:
** command_utils
*/

#include <string.h>

#include "constants.h"
#include "server/server.h"

static users_data_t *user_finder(ll_t *list, const char *data, bool is_login)
{
    ll_t *tmp = list;
    users_data_t *user_data = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        user_data = tmp->data;
        if (is_login == true && strcmp(user_data->name, data) == 0) {
            return user_data;
        }
        if (is_login == false && strcmp(user_data->uuid, data) == 0) {
            return user_data;
        }
    }
    return NULL;
}

static direct_message_t *dm_finder(ll_t *list, const char *data)
{
    ll_t *tmp = list;
    direct_message_t *dm = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        dm = tmp->data;
        if (strcmp(dm->receiver_uuid, data) == 0) {
            return dm;
        }
    }
    return NULL;
}

static teams_data_t *team_finder(ll_t *list, const char *data)
{
    ll_t *tmp = list;
    teams_data_t *team = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        team = tmp->data;
        if (strcmp(team->uuid, data) == 0) {
            return team;
        }
    }
    return NULL;
}

static channels_data_t *channel_finder(ll_t *list, const char *data)
{
    ll_t *tmp = list;
    channels_data_t *channel = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        channel = tmp->data;
        if (strcmp(channel->uuid, data) == 0) {
            return channel;
        }
    }
    return NULL;
}

static threads_data_t *thread_finder(ll_t *list, const char *data)
{
    ll_t *tmp = list;
    threads_data_t *thread = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        thread = tmp->data;
        if (strcmp(thread->uuid, data) == 0) {
            return thread;
        }
    }
    return NULL;
}

void *finder(ll_t *list, const char *data, bool is_login)
{
    if (list == NULL)
        return NULL;
    if (list->type == USERS) {
        return user_finder(list, data, is_login);
    }
    if (list->type == DIRECT_MESSAGE) {
        return dm_finder(list, data);
    }
    if (list->type == TEAMS) {
        return team_finder(list, data);
    }
    if (list->type == CHANNELS) {
        return channel_finder(list, data);
    }
    if (list->type == THREADS) {
        return thread_finder(list, data);
    }
    return NULL;
}
