/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_string.c
*/

#include <string.h>
#include "json.h"

size_t get_size_string(char *data, int tab_level)
{
    size_t total_size = 0;
    int ntl = tab_level + JSON_TAB_SIZE;

    my_putdebug("(gst) In get_size_string\n");
    total_size += ntl;
    total_size += strlen("char *") + JSON_QUOTATION_MARK + JSON_COLON;
    total_size += strlen(data) + JSON_QUOTATION_MARK;
    total_size += JSON_COMMA;
    my_putdebug("(gst) Out of get_size_string\n");
    return total_size;
}
