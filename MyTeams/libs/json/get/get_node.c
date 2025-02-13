/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_node.c
*/

#include "json.h"

json_t *get_node(json_t *json_data, int node_index)
{
    int i = 0;
    json_t *tmp;
    int ni = node_index;

    for (tmp = json_data; i < ni && tmp->next != NULL; tmp = tmp->next) {
        i++;
    }
    return tmp;
}
