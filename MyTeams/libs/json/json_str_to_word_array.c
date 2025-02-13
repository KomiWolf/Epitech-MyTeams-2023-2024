/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** json_str_to_word_array.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "json.h"

static bool is_a_sep(char chr, char *sep)
{
    int i = 0;

    for (; sep[i] != '\0'; i++) {
        if (chr == sep[i]) {
            return true;
        }
    }
    return false;
}

static int get_tab_height(char *str, char *seperator)
{
    int i = 0;
    int height = 0;

    for (; str[i] != '\0'; i++) {
        if (is_a_sep(str[i], seperator) == true) {
            height += 1;
        }
    }
    return height;
}

static int get_line_width(char *str, int istart, char *seperator)
{
    int j = istart;
    int counter = 0;

    for (; str[j] != '\0'; j++) {
        if (is_a_sep(str[j], seperator) == true) {
            return counter;
        }
        counter++;
    }
    return counter;
}

static char **manage_stuff(int *height, int *width, char *str, char *sep)
{
    char **array;

    *height = get_tab_height(str, sep);
    array = malloc(sizeof(char *) * (*height + 1));
    array[0] = malloc(sizeof(char) * (*width + 1));
    return array;
}

static void useless_overflow(char **array, int *x, int *y, int len)
{
    array[*y][*x] = '\0';
    *x = 0;
    *y = *y + 1;
    array[*y] = malloc(sizeof(char) * (len + 1));
}

char **json_str_to_word_array(char *str, char *sep, int *width, int *height)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int lw = 0;
    char **array;

    *width = get_line_width(str, i, sep);
    array = manage_stuff(height, width, str, sep);
    for (; str[i] != '\0'; i++) {
        if (is_a_sep(str[i], sep) == true) {
            lw = get_line_width(str, i + 1, sep);
            useless_overflow(array, &x, &y, lw);
            continue;
        }
        array[y][x] = str[i];
        x++;
    }
    free(array[y]);
    array[y] = NULL;
    return array;
}
