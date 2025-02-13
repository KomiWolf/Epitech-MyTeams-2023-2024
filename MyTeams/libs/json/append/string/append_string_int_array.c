/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_connected_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

static int append_string_int_inner(cn_t *cn, int data, int ntl, bool comma)
{
    char sata[JSON_MAX_BUFFER];

    sprintf(sata, "%d", data);
    append_string_tab(cn, ntl);
    strcat(cn->string, sata);
    if (comma) {
        strcat(cn->string, JSON_S_COMMA);
        cn->index += strlen(JSON_S_COMMA);
    } else {
        strcat(cn->string, JSON_S_NEW_LINE);
        cn->index += strlen(JSON_S_NEW_LINE);
    }
    cn->index += strlen(sata) + strlen(JSON_S_TAB);
    return JSON_SUCCESS;
}

int append_string_int_array(cn_t *cn, int *data, int ntl)
{
    int i = 0;
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_START);
    cn->index += strlen(JSON_S_LIST_START);
    for (; data[i] != JSON_INT_ARRAY_END; i++) {
        if (data[i + 1] == JSON_INT_ARRAY_END) {
            append_string_int_inner(cn, data[i], new_ntl, false);
        } else {
            append_string_int_inner(cn, data[i], new_ntl, true);
        }
    }
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_LIST_END);
    cn->index += strlen(JSON_S_LIST_END);
    return JSON_SUCCESS;
}
