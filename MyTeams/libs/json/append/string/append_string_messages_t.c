/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_messages_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct messages_s {
//     char *msg;
//     char *sender_uuid;
//     time_t sent_time;
//     char *sent_time_str;
// } messages_t;

int append_string_messages_t(cn_t *cn, messages_t *data, int ntl)
{
    char time[JSON_MAX_BUFFER];
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "messages_t", ntl);
    sprintf(time, "%ld", data->sent_time);
    cn->index += strlen(JSON_S_CURLY_START);
    append_string_dict_node(cn, JSON_S_NAME, "messages_t", new_ntl);
    append_string_dict_node(cn, "msg", data->msg, new_ntl);
    append_string_dict_node(cn, "sender_uuid", data->sender_uuid, new_ntl);
    append_string_dict_node(cn, "sent_time_str", data->sent_time_str, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    return JSON_SUCCESS;
}
