/*
** EPITECH PROJECT, 2024
** teams
** File description:
** count_array_length
*/

#include <stddef.h>

size_t count_array_length(char **array)
{
    size_t i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
