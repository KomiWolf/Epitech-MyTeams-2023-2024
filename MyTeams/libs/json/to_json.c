/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** to_json.c
*/

#include <stdio.h>
#include "json.h"

static void process_line(dn_t *d, json_t **data, char **array, int *i)
{
}

json_t *to_json(char *string)
{
    dn_t data;
    json_t *json_string;
    int i = 0;
    int width = 0;
    int height = 0;
    char **array = json_str_to_word_array(string, "\n", &width, &height);

    if (array == NULL) {
        return NULL;
    }
    for (; array[i] != NULL; i++) {
        process_line(&data, &json_string, array, &i);
    }
    return json_string;
}
