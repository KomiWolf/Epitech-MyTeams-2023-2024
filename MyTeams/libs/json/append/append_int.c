/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_int.c
*/

#include <stdlib.h>
#include "json.h"

int append_int(json_t *p_list, int value)
{
    int *number = malloc(sizeof(int));

    if (number == NULL) {
        return JSON_ERROR;
    }
    if (p_list == NULL) {
        free(number);
        return JSON_ERROR;
    }
    *number = value;
    return append_node(p_list, (void *)number, INT);
}
