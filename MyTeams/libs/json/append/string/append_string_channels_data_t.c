/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_channels_data_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct threads_data_s {
//     char *uuid;
//     char *user_uuid;
//     char *title;
//     char *body;
//     time_t created_time;
//     char *created_time_str;
//     ll_t *comments;
// } threads_data_t;

int append_string_channels_data_t(cn_t *cn, channels_data_t *data, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "channels_data_t", ntl);
    append_string_dict_node(cn, JSON_S_NAME, "channels_data_t", new_ntl);
    append_string_dict_node(cn, "uuid", data->uuid, new_ntl);
    append_string_dict_node(cn, "name", data->name, new_ntl);
    append_string_dict_node(cn, "description", data->description, new_ntl);
    append_linked_list_node(cn, "threads", data->threads, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    return JSON_SUCCESS;
}
