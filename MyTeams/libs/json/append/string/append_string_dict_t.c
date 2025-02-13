/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** append_string_dict_t.c
*/

#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct dict_s {
//     char *term;
//     void *definition;
//     data_type_t type;
// } dict_t;

static void append_string_dict_t_ovf(cn_t *cn, dict_t *data, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_correct_string(cn, data->definition, data->type, new_ntl);
    my_putdebug("(asdt) Added definition\n");
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    my_putdebug("(asdt) Out of append_string_dict_t\n");
}

int append_string_dict_t(cn_t *cn, dict_t *data, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;

    my_putdebug("(asdt) In append_string_dict_t\n");
    append_string_node_header(cn, "dict_t", ntl);
    my_putdebug("(asdt) Added json curly start\n");
    append_string_dict_node(cn, JSON_S_NAME, "dict_t", new_ntl);
    my_putdebug("(asdt) added node JSON_S_NAME : dict_t\n");
    append_string_dict_node(cn, "term", data->term, new_ntl);
    my_putdebug("(asdt) Added term: term\n");
    append_string_dict_t_ovf(cn, data, ntl);
    return JSON_SUCCESS;
}
