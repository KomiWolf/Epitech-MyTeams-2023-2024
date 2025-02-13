/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_direct_message_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct direct_message_s {
//     char *receiver_uuid;
//     ll_t *messages;
// } direct_message_t;

int append_string_direct_message_t(cn_t *cn, direct_message_t *data, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "direct_message_t", ntl);
    append_string_dict_node(cn, JSON_S_NAME, "direct_message_t", new_ntl);
    append_string_dict_node(cn, "receiver_uuid", data->receiver_uuid, new_ntl);
    append_linked_list_node(cn, "messages", data->messages, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    return JSON_SUCCESS;
}
