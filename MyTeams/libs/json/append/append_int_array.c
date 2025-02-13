/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_int_array.c
*/

#include <stdlib.h>
#include "json.h"

int append_int_array(json_t *p_list, int *array)
{
    if (p_list == NULL || array == NULL) {
        return JSON_ERROR;
    }
    return append_node(p_list, (void *)array, INT_ARRAY);
}
