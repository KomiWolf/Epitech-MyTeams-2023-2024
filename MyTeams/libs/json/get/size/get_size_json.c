/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** get_size_json_t.c
*/

#include <string.h>
#include <stdbool.h>
#include "json.h"


static size_t process_node(json_t *node, int tab, bool comma)
{
    size_t total_size = 0;

    total_size += get_string_size(node->data, node->type, tab);
    if (comma) {
        total_size += JSON_COMMA;
    } else {
        total_size += JSON_NEW_LINE;
    }
    return total_size;
}

size_t get_size_json_t(json_t *data, int tab_level)
{
    json_t *tmp = NULL;
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_LIST + (ntl * 2);
    if (data == NULL) {
        return total_size;
    }
    for (tmp = data; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->prev != NULL) {
            total_size += process_node(tmp->prev, ntl, true);
        }
        if (tmp->next == NULL)
            data = tmp;
    }
    if (data != NULL)
        total_size += process_node(data, ntl, true);
    if (tmp != NULL)
        total_size += process_node(tmp, ntl, false);
    return total_size;
}
