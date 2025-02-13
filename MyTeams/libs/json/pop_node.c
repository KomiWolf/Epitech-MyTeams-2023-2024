/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** pop_node.c
*/

#include <stdlib.h>
#include "json.h"

json_t *pop_node(json_t *json_data, int index)
{
    int i = 0;
    json_t *tmp = NULL;

    if (json_data == NULL)
        return json_data;
    for (tmp = json_data; i < index && tmp->next != NULL; tmp = tmp->next) {
        i++;
    }
    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    }
    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }
    free(tmp);
    return json_data;
}
