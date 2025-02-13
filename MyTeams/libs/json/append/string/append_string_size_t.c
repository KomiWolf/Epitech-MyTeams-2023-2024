/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_size_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

int append_string_size_t(cn_t *cn, size_t data, int ntl)
{
    char sata[JSON_MAX_BUFFER];

    sprintf(sata, "%zu", data);
    append_string_dict_node(cn, "size_t", sata, ntl);
    cn->index += strlen(sata) + JSON_COMMA;
    return JSON_SUCCESS;
}
