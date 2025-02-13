/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** get_size_messages_t.c
*/

#include <string.h>
#include "json.h"

static size_t get_node_size(char *name, char *data, int ntl)
{
    dict_t dictionnary;

    dictionnary.term = name;
    dictionnary.definition = (void *)data;
    dictionnary.type = STRING;
    return get_size_dict_t(&dictionnary, ntl) - JSON_CURLY;
}

size_t get_size_messages_t(messages_t *data, int tab_level)
{
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_CURLY + (tab_level * 2);
    if (data == NULL) {
        return total_size;
    }
    total_size += get_node_size((char *)JSON_S_NAME, "messages_t", ntl);
    total_size += JSON_COMMA;
    total_size += get_node_size("msg", data->msg, ntl) + JSON_COMMA;
    total_size += get_node_size("sender_uuid", data->sender_uuid, ntl);
    total_size += JSON_COMMA;
    total_size += get_node_size("sent_time_str", data->sent_time_str, ntl);
    total_size += JSON_COMMA;
    total_size += strlen("sent_time") + sizeof(data->sent_time) + JSON_COLON;
    total_size += ntl + JSON_COMMA;
    return total_size;
}
