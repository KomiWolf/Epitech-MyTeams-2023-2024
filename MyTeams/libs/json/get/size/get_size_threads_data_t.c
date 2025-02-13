/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** get_size_threads_data_t.c
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

size_t get_size_threads_data_t(threads_data_t *data, int tab_level)
{
    char *tmp = NULL;
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_CURLY + (tab_level * 2);
    if (data == NULL)
        return total_size;
    total_size += get_node_size((char *)JSON_S_NAME, "threads_data_t", ntl);
    total_size += JSON_COMMA * 2;
    total_size += get_node_size("uuid", data->uuid, ntl) + JSON_COMMA;
    total_size += get_node_size("user_uuid", data->user_uuid, ntl);
    total_size += get_node_size("title", data->title, ntl) + JSON_COMMA;
    total_size += get_node_size("body", data->body, ntl) + JSON_COMMA;
    tmp = data->created_time_str;
    total_size += get_node_size("created_time_str", tmp, ntl) + JSON_COMMA;
    total_size += strlen("comments") + JSON_COLON + JSON_NEW_LINE + ntl;
    total_size += get_string_size(data->comments, LINKED_LIST, ntl);
    total_size += strlen("created_time") + JSON_COLON + JSON_NEW_LINE + ntl;
    total_size += sizeof(data->created_time);
    return total_size;
}
