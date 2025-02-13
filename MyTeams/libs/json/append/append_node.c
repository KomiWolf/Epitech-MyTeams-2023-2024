/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_node.c
*/

#include <stdlib.h>
#include "json.h"

int append_node(json_t *json_data, void *node_content, data_type_t type)
{
    json_t *new_node = init_json(node_content, type);
    json_t *latest_node = json_data;

    if (new_node == NULL) {
        return JSON_ERROR;
    }
    if (json_data == NULL) {
        free(new_node);
        return JSON_ERROR;
    }
    for (; latest_node->next != NULL; latest_node = latest_node->next);
    latest_node->next = new_node;
    new_node->prev = latest_node;
    new_node->index = latest_node->index + 1;
    return JSON_SUCCESS;
}
