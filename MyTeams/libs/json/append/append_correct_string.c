/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_correct_string.c
*/

#include <stdlib.h>
#include <string.h>
#include "json.h"

static int append_correct_string_ovf3(cn_t *cn, void *data, dt_t type, int ntl)
{
    switch (type) {
        case SIZE_T:
            return append_string_size_t(cn, *((size_t *)data), ntl);
        case INT:
            return append_string_int(cn, (*((int *)data)), ntl);
        case CHAR:
            return append_string_char(cn, (*((char *)data)), ntl);
        case EMPTY:
            return JSON_SUCCESS;
        case UNKNOWN:
            return JSON_SUCCESS;
        default:
            return JSON_SUCCESS;
    }
}

static int append_correct_string_ovf2(cn_t *cn, void *data, dt_t type, int ntl)
{
    switch (type) {
        case INT_ARRAY:
            return append_string_int_array(cn, (int *)data, ntl);
        case STRING_ARRAY:
            return append_string_string_array(cn, (char **)data, ntl);
        case STRING:
            return append_string_string(cn, (char *)data, ntl);
        default:
            return append_correct_string_ovf3(cn, data, type, ntl);
    }
}

static int append_correct_string_ovf1(cn_t *cn, void *data, dt_t type, int ntl)
{
    switch (type) {
        case COMMENTS:
            return append_string_comments_data_t(cn, (codata_t *)data, ntl);
        case USERS:
            return append_string_users_data_t(cn, (users_data_t *)data, ntl);
        case DIRECT_MESSAGE:
            return append_string_direct_message_t(cn, (dmessage_t *)data, ntl);
        case MESSAGES:
            return append_string_messages_t(cn, (messages_t *)data, ntl);
        default:
            return append_correct_string_ovf2(cn, data, type, ntl);
    }
}

int append_correct_string(cnode_t *cn, void *data, dtype_t type, int ntl)
{
    cn->add_comma = true;
    if (data == NULL) {
        return JSON_ERROR;
    }
    switch (type) {
        case LINKED_LIST:
            return append_string_linked_list(cn, (llist_t *)data, ntl);
        case DICT:
            return append_string_dict_t(cn, (dict_t *)data, ntl);
        case TEAMS:
            return append_string_teams_data_t(cn, (teams_data_t *)data, ntl);
        case CHANNELS:
            return append_string_channels_data_t(cn, (chdata_t *)data, ntl);
        case THREADS:
            return append_string_threads_data_t(cn, (tdata_t *)data, ntl);
        default:
            return append_correct_string_ovf1(cn, data, type, ntl);
    }
}
