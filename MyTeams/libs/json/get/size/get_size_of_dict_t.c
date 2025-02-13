/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** get_size_of_dict_t.c
*/

#include <string.h>
#include "json.h"

size_t get_size_dict_t(dict_t *data, int tab_level)
{
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    total_size += JSON_CURLY + (tab_level * 2);
    total_size += JSON_QUOTATION_MARK + strlen("dict_t") + JSON_COLON;
    if (data == NULL) {
        return total_size;
    }
    total_size += strlen(data->term) + JSON_QUOTATION_MARK + ntl;
    total_size += JSON_COLON;
    total_size += get_string_size(data->definition, data->type, ntl);
    return total_size;
}
