/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** to_string.c
*/

#include <stdlib.h>
#include <string.h>
#include "json.h"

static size_t get_all_string_sizes(json_t *data)
{
    size_t length = 0;
    ll_t *tmp = NULL;

    for (tmp = data; tmp != NULL; tmp = tmp->next) {
        my_putdebug("(ts) In get_string_size\n");
        length += get_string_size(tmp->data, tmp->type, JSON_TAB_SIZE);
        my_putdebug("(ts) Out of get_string_size\n");
    }
    return length;
}

static void append_all_strings(carrier_node_t *cn, json_t *data)
{
    ll_t *tmp = NULL;

    for (tmp = data; tmp != NULL; tmp = tmp->next) {
        my_putdebug("(ts) In append_correct_string\n");
        append_correct_string(cn, tmp->data, tmp->type, JSON_TAB_SIZE);
        my_putdebug("(ts) Out of append_correct_string\n");
    }
}

char *to_string(json_t *json_data)
{
    carrier_node_t data;

    data.max_size = get_all_string_sizes(json_data);
    data.index = 0;
    data.max_size += JSON_CURLY;
    data.string = malloc(sizeof(char) * data.max_size + 1);
    if (data.string == NULL || json_data == NULL) {
        return NULL;
    }
    memset((void *)data.string, '\0', data.max_size);
    strcpy(data.string, JSON_S_CURLY_START);
    data.index += strlen(JSON_S_CURLY_START);
    append_all_strings(&data, json_data);
    strcat(data.string, JSON_S_CURLY_END);
    data.index += strlen(JSON_S_CURLY_END);
    return data.string;
}
