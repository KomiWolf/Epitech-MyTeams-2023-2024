/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_char.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

int append_string_char(cn_t *cn, char data, int ntl)
{
    char tmp[4];

    cn->add_comma = true;
    memset((void *)tmp, '\0', 4);
    tmp[0] = data;
    tmp[1] = '\0';
    append_string_dict_node(cn, "char", tmp, ntl);
    return JSON_SUCCESS;
}
