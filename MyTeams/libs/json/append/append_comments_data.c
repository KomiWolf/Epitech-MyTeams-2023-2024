/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_comments_data.c
*/

#include <stddef.h>
#include "json.h"

int append_comments_data(json_t *p_list, comments_data_t *child)
{
    if (p_list == NULL || child == NULL) {
        return JSON_ERROR;
    }
    return append_node(p_list, (void *)child, COMMENTS);
}
