/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_node_header.c
*/

#include <string.h>
#include "json.h"

int append_string_node_header(cn_t *cn, char *str, int ntl)
{
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_QUOTATION_MARK_START);
    strcat(cn->string, str);
    strcat(cn->string, JSON_S_QUOTATION_MARK_END);
    strcat(cn->string, JSON_S_COLON);
    strcat(cn->string, JSON_S_CURLY_START);
    cn->index += strlen(JSON_S_QUOTATION_MARK_START) + strlen(str);
    cn->index += strlen(JSON_S_QUOTATION_MARK_END) + strlen(JSON_S_COLON);
    cn->index += strlen(JSON_S_CURLY_START);
    return JSON_SUCCESS;
}
