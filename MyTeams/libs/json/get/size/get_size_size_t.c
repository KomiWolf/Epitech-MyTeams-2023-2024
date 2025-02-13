/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_size_t.c
*/

#include <stdio.h>
#include <string.h>
#include "json.h"

static size_t get_node_size(char *name, char *data, int ntl)
{
    dict_t dictionnary;

    dictionnary.term = name;
    dictionnary.definition = (void *)data;
    dictionnary.type = STRING;
    return get_size_dict_t(&dictionnary, ntl) - JSON_CURLY;
}

size_t get_size_size_t(size_t data, int tab_level)
{
    size_t total_size = 0;
    char tmp[JSON_MAX_BUFFER];
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += ntl;
    sprintf(tmp, "%ld", data);
    total_size += get_node_size("size_t", tmp, ntl);
    total_size += JSON_COMMA;
    return total_size;
}
