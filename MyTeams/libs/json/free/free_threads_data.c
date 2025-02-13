/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_threads_data.c
*/

#include <stdlib.h>
#include "json.h"

int free_threads_data(threads_data_t *data)
{
    int status = JSON_SUCCESS;

    if (data == NULL) {
        return JSON_ERROR;
    }
    free(data->uuid);
    free(data->user_uuid);
    free(data->title);
    free(data->body);
    free(data->created_time_str);
    status = free_node_content((void *)data->comments, LINKED_LIST);
    if (status == JSON_SUCCESS) {
        free(data);
    }
    return status;
}
