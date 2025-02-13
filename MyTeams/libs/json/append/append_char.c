/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_char.c
*/

#include <stdlib.h>
#include "json.h"

int append_char(json_t *p_list, char character)
{
    char *character_input = malloc(sizeof(char));

    if (character_input == NULL) {
        return JSON_ERROR;
    }
    if (p_list == NULL) {
        free(character_input);
        return JSON_ERROR;
    }
    *character_input = character;
    return append_node(p_list, (void *)character_input, CHAR);
}
