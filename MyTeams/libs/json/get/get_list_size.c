/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_list_size.c
*/

#include <stddef.h>
#include "json.h"

int get_list_size(json_t *json_data)
{
    int size = 0;
    json_t *tmp = NULL;

    for (tmp = json_data; tmp != NULL; tmp = tmp->next) {
        size++;
    }
    return size;
}
