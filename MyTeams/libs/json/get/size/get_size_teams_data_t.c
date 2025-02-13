/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** get_size_teams_data_t.c
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

size_t get_size_teams_data_t(teams_data_t *data, int tab_level)
{
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_CURLY + (tab_level * 2);
    total_size += JSON_COLON + JSON_QUOTATION_MARK + strlen("teams_data_t");
    if (data == NULL) {
        return total_size;
    }
    total_size += get_node_size((char *)JSON_S_NAME, "teams_data_t", ntl);
    total_size += JSON_COMMA;
    total_size += get_node_size("uuid", data->uuid, ntl) + JSON_COMMA;
    total_size += get_node_size("name", data->name, ntl) + JSON_COMMA;
    total_size += get_node_size("description", data->description, ntl);
    total_size += JSON_COMMA;
    total_size += strlen("channels") + JSON_COLON + JSON_NEW_LINE + ntl;
    total_size += get_string_size(data->channels, LINKED_LIST, ntl);
    return total_size;
}
