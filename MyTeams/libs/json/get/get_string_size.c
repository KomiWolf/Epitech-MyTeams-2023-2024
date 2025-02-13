/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_string_size.c
*/

#include <stdlib.h>
#include <string.h>
#include "json.h"

static size_t get_string_size_ovf3(void *data, data_type_t type, int ntl)
{
    ntl += JSON_TAB_SIZE;
    switch (type) {
        case STRING_ARRAY:
            return get_size_string_array((char **)data, ntl);
        case SIZE_T:
            return get_size_size_t(*((size_t *)data), ntl);
        case INT:
            return get_size_integer(*((int *)data), ntl);
        case CHAR:
            return get_size_char((*(char *)data), ntl);
        case EMPTY:
            return JSON_EMPTY;
        case UNKNOWN:
            return JSON_EMPTY;
        default:
            return JSON_EMPTY;
    }
}

static size_t get_string_size_ovf2(void *data, data_type_t type, int ntl)
{
    size_t tmp = 0;

    switch (type) {
        case MESSAGES:
            return get_size_messages_t((messages_t *)data, ntl);
        case INT_ARRAY:
            return get_size_int_array((int *)data, ntl);
        case STRING:
            my_putdebug("(gss) In STRING\n");
            tmp = get_size_string((char *)data, ntl);
            my_putdebug("(gss) Out of STRING\n");
            return tmp;
        default:
            return get_string_size_ovf3(data, type, ntl);
    }
}

static size_t get_string_size_ovf1(void *data, data_type_t type, int ntl)
{
    size_t tmp = 0;

    switch (type) {
        case CHANNELS:
            return get_size_channels_data_t((channels_data_t *)data, ntl);
        case THREADS:
            return get_size_threads_data_t((threads_data_t *)data, ntl);
        case COMMENTS:
            return get_size_comments_data_t((comments_data_t *)data, ntl);
        case USERS:
            return get_size_users_data_t((users_data_t *)data, ntl);
        case DIRECT_MESSAGE:
            return get_size_direct_message_t((direct_message_t *)data, ntl);
        default:
            my_putdebug("(gss) In default (ovf1)\n");
            tmp = get_string_size_ovf2(data, type, ntl);
            my_putdebug("(gss) Out of default (ovf1)\n");
            return tmp;
    }
}

size_t get_string_size(void *data, data_type_t type, int tab_level)
{
    size_t tmp = 0;
    int ntl = tab_level + 0;

    if (data == NULL) {
        my_putdebug("(gss) data = NULL\n");
        return JSON_CURLY;
    }
    switch (type) {
        case LINKED_LIST:
            return get_size_json_t((json_t *)data, ntl);
        case DICT:
            return get_size_dict_t((dict_t *)data, ntl);
        case TEAMS:
            return get_size_teams_data_t((teams_data_t *)data, ntl);
        default:
            my_putdebug("(gss) In default get_string_size\n");
            tmp = get_string_size_ovf1(data, type, ntl);
            my_putdebug("(gss) Out of default get_string_size\n");
            return tmp;
    }
}
