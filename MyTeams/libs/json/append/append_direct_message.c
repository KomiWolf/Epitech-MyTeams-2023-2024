/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_direct_message.c
*/

#include <stddef.h>
#include "json.h"

int append_direct_message(json_t *p_list, direct_message_t *child)
{
    if (p_list == NULL || child == NULL) {
        return JSON_ERROR;
    }
    return append_node(p_list, (void *)child, DIRECT_MESSAGE);
}
