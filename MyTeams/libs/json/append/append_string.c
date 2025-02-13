/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string.c
*/

#include <stdlib.h>
#include <string.h>
#include "json.h"

int append_string(json_t *p_list, char *string)
{
    char *copy = NULL;

    if (p_list == NULL || string == NULL) {
        return JSON_ERROR;
    }
    copy = strdup(string);
    if (copy == NULL) {
        return JSON_ERROR;
    }
    return append_node(p_list, (void *)copy, STRING);
}
