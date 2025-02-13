/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_int_array.c
*/

#include <stdlib.h>
#include "json.h"

int free_int_array(int *array)
{
    if (array == NULL) {
        return JSON_ERROR;
    }
    free(array);
    return JSON_SUCCESS;
}
