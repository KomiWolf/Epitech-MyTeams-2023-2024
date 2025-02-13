/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** init_json.c
*/

#include <stdlib.h>
#include "json.h"

json_t *init_json(void *node_content, data_type_t type)
{
    json_t *node = malloc(sizeof(json_t));

    if (node == NULL) {
        return NULL;
    }
    node->index = 0;
    node->data = node_content;
    node->type = type;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
