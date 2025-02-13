/*
** EPITECH PROJECT, 2024
** teams
** File description:
** special_str_to_word_array
*/

#include <malloc.h>
#include <string.h>
#include <stdbool.h>

static int count_char(const char *str, const int current_index)
{
    int count = 0;

    for (int i = current_index; str[i] != '\0'; i++) {
        if (str[i] != '"') {
            count++;
        } else {
            return count;
        }
    }
    return count;
}

static int count_double_quote(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"') {
            count++;
        }
    }
    if ((count % 2) != 0) {
        return 0;
    }
    count++;
    return count;
}

static size_t fill_first_index(char **tab, const char *str, size_t *j)
{
    size_t i = 0;
    int count = count_char(str, 0);

    tab[0] = malloc(sizeof(char) * (count + 1));
    for (size_t x = 0; str[x] != '\0'; x++) {
        if (str[x] == ' ' || str[x] == '"' ||
        str[x] == '\r' || str[x] == '\n') {
            tab[0][i] = '\0';
            (*j)++;
            return x + 1;
        }
        tab[0][i] = str[x];
        i++;
    }
    tab[0][i] = '\0';
    (*j)++;
    return 0;
}

static void fill_special_array(char **t, const char *str, size_t *j, size_t *i)
{
    bool is_inside_quote_string = false;

    for (size_t x = fill_first_index(t, str, j); str[x] != '\0'; x++) {
        if (is_inside_quote_string == false && str[x] == '"') {
            t[*j] = malloc(sizeof(char) * (count_char(str, (x + 1)) + 1));
            is_inside_quote_string = true;
            continue;
        }
        if (is_inside_quote_string == true && str[x] == '"') {
            is_inside_quote_string = false;
            t[*j][*i] = '\0';
            (*j)++;
            *i = 0;
            continue;
        }
        if (is_inside_quote_string == true) {
            t[*j][*i] = str[x];
            (*i)++;
        }
    }
}

char **special_str_to_word_array(const char *str)
{
    int count = count_double_quote(str);
    char **tab = NULL;
    size_t j = 0;
    size_t i = 0;

    if (count == 0) {
        return NULL;
    }
    tab = malloc(sizeof(char *) * (count + 1));
    fill_special_array(tab, str, &j, &i);
    tab[j] = NULL;
    return tab;
}
