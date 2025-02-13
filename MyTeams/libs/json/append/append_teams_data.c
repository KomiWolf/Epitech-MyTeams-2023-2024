/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_teams_data.c
*/

#include <stddef.h>
#include "json.h"

int append_teams_data(json_t *parent_list, teams_data_t *child)
{
    if (parent_list == NULL || child == NULL) {
        return JSON_ERROR;
    }
    return append_node(parent_list, (void *)child, TEAMS);
}
