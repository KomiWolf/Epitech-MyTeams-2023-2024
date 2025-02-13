/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_threads_data_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct channels_data_s {
//     char *uuid;
//     char *name;
//     char *description;
//     ll_t *threads;
// } channels_data_t;

int append_string_threads_data_t(cn_t *cn, threads_data_t *data, int ntl)
{
    char tmp_time[JSON_MAX_BUFFER];
    char *tmp2 = data->created_time_str;
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "threads_data_t", ntl);
    sprintf(tmp_time, "%ld", data->created_time);
    append_string_dict_node(cn, JSON_S_NAME, "threads_data_t", new_ntl);
    append_string_dict_node(cn, "uuid", data->uuid, new_ntl);
    append_string_dict_node(cn, "user_uuid", data->user_uuid, new_ntl);
    append_string_dict_node(cn, "title", data->title, new_ntl);
    append_string_dict_node(cn, "body", data->body, new_ntl);
    append_string_dict_node(cn, "created_time", tmp_time, new_ntl);
    append_string_dict_node(cn, "created_time_str", tmp2, new_ntl);
    append_linked_list_node(cn, "comments", data->comments, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_START);
    return JSON_SUCCESS;
}
