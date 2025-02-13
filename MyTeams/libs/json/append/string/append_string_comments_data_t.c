/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_comments_data_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct comments_data_s {
//     char *user_uuid;
//     char *reply_body;
//     time_t replied_time;
//     char *replied_time_str;
// } comments_data_t;

int append_string_comments_data_t(cn_t *cn, comments_data_t *data, int ntl)
{
    char tmp_time[JSON_MAX_BUFFER];
    char *tmp = data->replied_time_str;
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "comments_data_t", ntl);
    sprintf(tmp_time, "%ld", data->replied_time);
    append_string_dict_node(cn, JSON_S_NAME, "comments_data_t", new_ntl);
    append_string_dict_node(cn, "user_uuid", data->user_uuid, new_ntl);
    append_string_dict_node(cn, "reply_body", data->reply_body, new_ntl);
    append_string_dict_node(cn, "replied_time_str", tmp, new_ntl);
    append_string_dict_node(cn, "replied_time", tmp_time, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    return JSON_SUCCESS;
}
