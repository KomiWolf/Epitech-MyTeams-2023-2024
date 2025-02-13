/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_linked_list.c
*/

#include <stddef.h>
#include "json.h"

int append_linked_list(json_t *parent_list, json_t *child_list)
{
    if (parent_list == NULL || child_list == NULL) {
        return JSON_ERROR;
    }
    return append_node(parent_list, (void *)child_list, LINKED_LIST);
}
