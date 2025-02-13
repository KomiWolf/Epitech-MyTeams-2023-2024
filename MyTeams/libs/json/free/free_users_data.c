/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_users_data.c
*/

#include <stdlib.h>
#include "json.h"

int free_users_data(users_data_t *data)
{
    int status = JSON_SUCCESS;
    int status2 = JSON_SUCCESS;

    if (data == NULL) {
        return JSON_ERROR;
    }
    free(data->uuid);
    free(data->name);
    status = free_node_content((void *)data->teams_uuid, LINKED_LIST);
    status2 = free_node_content((void *)data->dm, LINKED_LIST);
    if (status != JSON_SUCCESS) {
        return status;
    } else if (status2 != JSON_SUCCESS) {
        return status2;
    } else {
        free(data);
        return JSON_SUCCESS;
    }
}
