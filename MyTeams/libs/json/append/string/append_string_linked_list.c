/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** append_string_linked_list.c
*/

#include <stddef.h>
#include <string.h>
#include "json.h"

int append_string_linked_list(cn_t *cn, llist_t *ll, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;
    llist_t *tmp = ll;

    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_START);
    cn->index += ((int)JSON_LIST / 2);
    for (; tmp != NULL; tmp = tmp->next) {
        append_correct_string(cn, tmp->data, tmp->type, new_ntl);
    }
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_END);
    cn->index += ((int)JSON_LIST / 2);
    return JSON_SUCCESS;
}
