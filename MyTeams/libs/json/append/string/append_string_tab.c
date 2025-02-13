/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
** File description:
** append_string_tab.c
*/

#include <string.h>
#include "json.h"

int append_string_tab(cn_t *cn, int ntl)
{
    int i = 0;

    for (; i < ntl; i += JSON_TAB_SIZE) {
        strcat(cn->string, JSON_S_TAB);
        cn->index += JSON_TAB_SIZE;
    }
    return JSON_SUCCESS;
}
