/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_empty_slot.c
*/

#include <stdlib.h>
#include "json.h"

int append_empty_slot(json_t *p_list)
{
    if (p_list == NULL) {
        return JSON_ERROR;
    }
    return append_node(p_list, (void *)NULL, EMPTY);
}
