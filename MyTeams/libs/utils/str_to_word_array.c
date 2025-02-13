/*
** EPITECH PROJECT, 2024
** teams
** File description:
** str_to_word_array
*/

#include <malloc.h>
#include <string.h>

static int count_string_character(const char *str, const char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != sep)
            count++;
        else
            return count;
    }
    return count;
}

static int count_string_number(const char *str, const char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
        count++;
    }
    count++;
    return count;
}

static int jump_n(int n, int size, const char *str, const char sep)
{
    int new_n = size + n;

    while (str[new_n] == sep) {
        if (str[new_n] == '\0') {
            return new_n;
        }
        new_n = new_n + 1;
    }
    return new_n;
}

char **str_to_word_array(const char *str, const char sep)
{
    int count = count_string_number(str, sep);
    char **tab = malloc(sizeof(char *) * (count + 1));
    int n = 0;
    int line = 0;
    int size = 0;
    char *copy = NULL;

    while (str[n] != '\0' && line < count) {
        size = count_string_character(str + n, sep);
        copy = malloc(sizeof(char) * (size + 1));
        strncpy(copy, str + n, size);
        copy[size] = '\0';
        tab[line] = copy;
        line++;
        n = jump_n(n, size, str, sep);
    }
    tab[line] = NULL;
    return tab;
}
