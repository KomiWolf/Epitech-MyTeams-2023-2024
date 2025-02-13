/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_string_array.c
*/

#include <string.h>
#include "json.h"

static size_t get_string_size_inner(char *string, int ntl, bool comma)
{
    size_t size = 0;

    size += strlen(string) + JSON_QUOTATION_MARK + ntl;
    if (comma) {
        size += JSON_COMMA;
    } else {
        size += JSON_NEW_LINE;
    }
    return size;
}

size_t get_size_string_array(char **data, int tab_level)
{
    int i = 0;
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_LIST + ntl;
    if (data == NULL) {
        return total_size;
    }
    for (; data[i] != NULL; i++) {
        if (data[i + 1] == NULL) {
            total_size += get_string_size_inner(data[i], ntl, false);
        } else {
            total_size += get_string_size_inner(data[i], ntl, true);
        }
    }
    total_size -= JSON_LIST_INNER_SIZE;
    total_size += JSON_COMMA;
    return total_size;
}
