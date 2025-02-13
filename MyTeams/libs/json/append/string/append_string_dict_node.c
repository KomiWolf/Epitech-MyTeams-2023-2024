/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** append_string_dict_node.c
*/

#include <stdio.h>
#include <string.h>
#include "json.h"

static void process_node(cn_t *cn, char const *data)
{
    strcat(cn->string, JSON_S_QUOTATION_MARK_START);
    cn->index += strlen(JSON_S_QUOTATION_MARK_START);
    if (data == NULL) {
        strcat(cn->string, JSON_S_NULL_STRING);
        cn->index += strlen(JSON_S_NULL_STRING);
    } else {
        strcat(cn->string, data);
        cn->index += strlen(data);
    }
    strcat(cn->string, JSON_S_QUOTATION_MARK_END);
    cn->index += strlen(JSON_S_QUOTATION_MARK_END);
}

/**
** @brief Function in charge of adding a line for a dictionnary
** @param cn Structure in charge of tracking general data for construction
** @param t Variable representing the term of the node
** @param d Variable reprensting  the definition of the node
** @param ntl Variable in charge of tracking the indentation level
**/
int append_string_dict_node(cn_t *cn, char const *t, char const *d, int ntl)
{
    my_putdebug("(asdn) In Append string dict node\n");
    append_string_tab(cn, ntl);
    process_node(cn, t);
    strcat(cn->string, JSON_S_COLON);
    process_node(cn, d);
    if (cn->add_comma) {
        strcat(cn->string, JSON_S_COMMA);
        cn->index += JSON_COMMA;
    }
    cn->index += (JSON_QUOTATION_MARK * 2);
    my_putdebug("(adsn) Out of Append string dict node\n");
    return JSON_SUCCESS;
}
