/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** append_string_teams_data_t.c
*/


#include <stdio.h>
#include <string.h>
#include "json.h"

// typedef struct teams_data_s {
//     char *uuid;
//     char *name;
//     char *description;
//     ll_t *channels;
// } teams_data_t;

int append_string_teams_data_t(cn_t *cn, teams_data_t *data, int ntl)
{
    int new_ntl = ntl + JSON_TAB_SIZE;

    append_string_node_header(cn, "teams_data_t", ntl);
    append_string_dict_node(cn, JSON_S_NAME, "teams_data_t", new_ntl);
    append_string_dict_node(cn, "uuid", data->uuid, new_ntl);
    append_string_dict_node(cn, "name", data->name, new_ntl);
    append_string_dict_node(cn, "description", data->description, new_ntl);
    append_linked_list_node(cn, "channels", data->channels, new_ntl);
    append_string_tab(cn, ntl);
    strcat(cn->string, JSON_S_CURLY_END);
    cn->index += strlen(JSON_S_CURLY_END);
    return JSON_SUCCESS;
}
