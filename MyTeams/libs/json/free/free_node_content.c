/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_node_content.c
*/

#include <stdlib.h>
#include "json.h"

static int free_node_content_ovf3(void *data, data_type_t type)
{
    switch (type) {
        case STRING:
            my_putdebug("(fnco3) Free node content: String\n");
            free(data);
            return JSON_SUCCESS;
        case SIZE_T:
            my_putdebug("(fnco3) Free node content: Size_t\n");
            free(data);
            return JSON_SUCCESS;
        case CHAR:
            my_putdebug("(fnco3) Free node content: CHAR\n");
            free(data);
            return JSON_SUCCESS;
        default:
            my_putdebug("(fnco3) Free node content: Default\n");
            return JSON_ERROR;
    }
}

static int free_node_content_ovf2(void *data, data_type_t type)
{
    switch (type) {
        case MESSAGES:
            my_putdebug("(fnco2) Free node content: messages_t\n");
            return free_messages((messages_t *)data);
        case INT_ARRAY:
            my_putdebug("(fnco2) Free node content: Int_Array\n");
            return free_int_array((int *)data);
        case STRING_ARRAY:
            my_putdebug("(fnco2) Free node content: String_Array\n");
            return free_string_array((char **)data);
        case UNKNOWN:
            my_putdebug("(fnco2) Free node content: UNKNOWN\n");
            free(data);
            return JSON_SUCCESS;
        case EMPTY:
            my_putdebug("(fnco2) Free node content: EMPTY\n");
            return JSON_SUCCESS;
        default:
            return free_node_content_ovf3(data, type);
    }
}

static int free_node_content_ovf1(void *data, data_type_t type)
{
    switch (type) {
        case CHANNELS:
            my_putdebug("(fnco1) Free node content: channels_data_t\n");
            return free_channels_data((channels_data_t *)data);
        case THREADS:
            my_putdebug("(fnco1) Free node content: threads_data_t\n");
            return free_threads_data((threads_data_t *)data);
        case COMMENTS:
            my_putdebug("(fnco1) Free node content: comments_data_t\n");
            return free_comments_data((comments_data_t *)data);
        case USERS:
            my_putdebug("(fnco1) Free node content: users_data_t\n");
            return free_users_data((users_data_t *)data);
        case DIRECT_MESSAGE:
            my_putdebug("(fnco1) Free node content: direct_message_t\n");
            return free_direct_message((direct_message_t *)data);
        default:
            return free_node_content_ovf2(data, type);
    }
}

int free_node_content(void *data, data_type_t type)
{
    if (data == NULL) {
        my_putdebug("(fnc) Free node content: NULL\n");
        return JSON_ERROR;
    }
    switch (type) {
        case LINKED_LIST:
            my_putdebug("(fnc) Free node content: json_t\n");
            return free_json((json_t *)data);
        case DICT:
            my_putdebug("(fnc) Free node content: dict_t\n");
            return free_dict((dict_t *)data);
        case TEAMS:
            my_putdebug("(fnc) Free node content: teams_data_t\n");
            return free_teams_data((teams_data_t *)data);
        case INT:
            my_putdebug("(fnc) Free node content: Int\n");
            return free_int((int *)data);
        default:
            return free_node_content_ovf1(data, type);
    }
}
