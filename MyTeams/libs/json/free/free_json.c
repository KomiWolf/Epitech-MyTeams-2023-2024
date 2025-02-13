/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_json.c
*/

#include <stdlib.h>
#include "json.h"

static void free_current_node(json_t *node)
{
    int status = 0;

    my_putdebug("(fj) In free_current_node\n");
    status = free_node_content(node->data, node->type);
    if (status == JSON_SUCCESS) {
        my_putdebug("(fj) free_node_content status = SUCCESS\n");
    } else {
        my_putdebug("(fj) free_node_content status = ERROR\n");
    }
    free(node);
    my_putdebug("(fj) Out of free_current_node\n");
}

static void process_child_node(json_t *ll)
{
    if (ll != NULL) {
        my_putdebug("(fj) In ll != NULL\n");
        free_current_node(ll);
        my_putdebug("(fj) Out of ll != NULL\n");
    }
}

static int free_nodes(json_t *ll)
{
    json_t *tmp = NULL;

    my_putdebug("(fj) In free_nodes\n");
    for (tmp = ll; tmp != NULL; tmp = tmp->next) {
        if (tmp->prev != NULL) {
            my_putdebug("(fj) In tmp->prev != NULL\n");
            free_current_node(tmp->prev);
            my_putdebug("(fj) Out of tmp->prev != NULL\n");
        }
        if (tmp->next == NULL) {
            my_putdebug("(fj) In tmp->next == NULL\n");
            ll = tmp;
            my_putdebug("(fj) Out of tmp->next == NULL\n");
        }
    }
    process_child_node(ll);
    my_putdebug("(fj) Out of free_nodes\n");
    return JSON_SUCCESS;
}

int free_json(json_t *json_data)
{
    int status = JSON_SUCCESS;

    if (json_data != NULL) {
        status = free_nodes(json_data);
        return status;
    }
    return JSON_ERROR;
}
