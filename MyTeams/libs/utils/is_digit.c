/*
** EPITECH PROJECT, 2024
** teams
** File description:
** is_digit
*/

#include <stdbool.h>

bool is_digit(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
