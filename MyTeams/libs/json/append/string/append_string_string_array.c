/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_string_array.c
*/


#include <stddef.h>
#include <string.h>
#include "json.h"

static void append_string_inner(cn_t *cn, char *string, int ntl, bool comma)
{
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_QUOTATION_MARK_START);
    strcat(cn->string, string);
    strcat(cn->string, JSON_S_QUOTATION_MARK_END);
    if (comma) {
        strcat(cn->string, JSON_S_COMMA);
        cn->index += strlen(JSON_S_COMMA);
    } else {
        strcat(cn->string, JSON_S_NEW_LINE);
        cn->index += strlen(JSON_S_NEW_LINE);
    }
    cn->index += strlen(JSON_S_QUOTATION_MARK_START) + strlen(string);
    cn->index += strlen(JSON_S_QUOTATION_MARK_END);
}

int append_string_string_array(cn_t *cn, char **data, int ntl)
{
    int i = 0;
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_START);
    cn->index += strlen(JSON_S_LIST_START);
    for (; data[i] != NULL; i++) {
        if (data[i + 1] == NULL) {
            append_string_inner(cn, data[i], new_ntl, false);
        } else {
            append_string_inner(cn, data[i], new_ntl, true);
        }
    }
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_END);
    cn->index += strlen(JSON_S_LIST_START);
    return JSON_SUCCESS;
}
