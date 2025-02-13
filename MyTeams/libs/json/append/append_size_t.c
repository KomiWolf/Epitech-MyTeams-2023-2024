/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_size_t.c
*/

#include <stdlib.h>
#include "json.h"

int append_size_t(json_t *p_list, size_t value)
{
    size_t *number = malloc(sizeof(size_t));

    if (number == NULL) {
        return JSON_ERROR;
    }
    if (p_list == NULL) {
        free(number);
        return JSON_ERROR;
    }
    *number = value;
    return append_node(p_list, (void *)number, SIZE_T);
}
