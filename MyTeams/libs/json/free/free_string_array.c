/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** free_string_array.c
*/

#include <stdlib.h>
#include "json.h"

int free_string_array(char **array)
{
    int i = 0;

    if (array == NULL) {
        return JSON_ERROR;
    }
    for (; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return JSON_SUCCESS;
}
