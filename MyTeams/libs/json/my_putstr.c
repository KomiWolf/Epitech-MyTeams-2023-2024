/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include <string.h>
#include "json.h"

void my_putstri(char const *string, int channel)
{
    write(channel, string, strlen(string));
}

void my_perror(char const *string)
{
    my_putstri(string, JSON_STANDARD_OUTPUT);
}

void my_putstr(char const *string)
{
    my_putstri(string, JSON_ERROR_OUTPUT);
}

void my_putdebug(char const *string)
{
    my_putstri(string, JSON_DEBUG_OUTPUT);
}
