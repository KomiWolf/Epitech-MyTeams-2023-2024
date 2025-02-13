/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_int.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

int append_string_int(cn_t *cn, int data, int ntl)
{
    char sata[JSON_MAX_BUFFER];

    sprintf(sata, "%d", data);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_QUOTATION_MARK_START);
    strcat(cn->string, "int");
    strcat(cn->string, JSON_S_QUOTATION_MARK_END);
    strcat(cn->string, JSON_S_COLON);
    strcat(cn->string, sata);
    strcat(cn->string, JSON_S_COMMA);
    cn->index += strlen(sata) + JSON_COMMA + strlen(JSON_S_COLON);
    cn->index += strlen(JSON_S_QUOTATION_MARK_START);
    cn->index += strlen(JSON_S_QUOTATION_MARK_END);
    return JSON_SUCCESS;
}
