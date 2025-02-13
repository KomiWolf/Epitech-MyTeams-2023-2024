/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_int.c
*/

#include <stdlib.h>
#include "json.h"

int free_int(int *data)
{
    free(data);
    return JSON_SUCCESS;
}
