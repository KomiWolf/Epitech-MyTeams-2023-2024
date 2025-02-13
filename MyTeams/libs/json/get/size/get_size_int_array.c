/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_int_array.c
*/

#include <string.h>
#include "json.h"

static size_t get_integer_size(int number, bool comma)
{
    size_t size = 0;

    while (number > 0) {
        number /= 10;
        size += 1;
    }
    if (comma) {
        size += JSON_COMMA;
    } else {
        size += JSON_NEW_LINE;
    }
    return size;
}

size_t get_size_int_array(int *data, int tab_level)
{
    int i = 0;
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_LIST + (tab_level * 2);
    if (data == NULL) {
        return total_size;
    }
    total_size += ntl;
    for (; data[i] != JSON_INT_ARRAY_END; i++) {
        total_size += ntl;
        if (data[i + 1] == JSON_INT_ARRAY_END) {
            total_size += get_integer_size(data[i], false);
        } else {
            total_size += get_integer_size(data[i], true);
        }
    }
    return total_size;
}
