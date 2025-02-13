/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** get_size_of_interger.c
*/

#include <string.h>
#include "json.h"

size_t get_size_integer(int number, int ntl)
{
    size_t size = 0;

    size += ntl + JSON_TAB_SIZE + JSON_COMMA + strlen("int");
    size += JSON_QUOTATION_MARK + JSON_COLON;
    while (number > 0) {
        number /= 10;
        size += 1;
    }
    return size;
}
