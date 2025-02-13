/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_string.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

int append_string_string(cn_t *cn, char *data, int ntl)
{
    append_string_dict_node(cn, "char *", data, ntl);
    cn->index += strlen(data) + JSON_COMMA + JSON_QUOTATION_MARK;
    return JSON_SUCCESS;
}
