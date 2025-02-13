/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_char.c
*/


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

size_t get_size_char(char data, int tab_level)
{
    size_t total_size = 0;
    char buff[4];
    int ntl = tab_level + JSON_TAB_SIZE;

    buff[0] = data;
    buff[1] = '\0';
    total_size += ntl;
    total_size += get_node_size("char", buff, ntl);
    total_size += JSON_COMMA;
    return total_size;
}
