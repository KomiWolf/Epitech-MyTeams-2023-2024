/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_teams_data.c
*/

#include <stdlib.h>
#include "json.h"

int free_teams_data(teams_data_t *data)
{
    int status = JSON_SUCCESS;

    if (data == NULL) {
        return JSON_ERROR;
    }
    free(data->uuid);
    free(data->name);
    free(data->description);
    status = free_node_content((void *)data->channels, LINKED_LIST);
    if (status == JSON_SUCCESS) {
        free(data);
    }
    return status;
}
