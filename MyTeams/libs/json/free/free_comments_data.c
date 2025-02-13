/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_comments_data.c
*/

#include <stdlib.h>
#include "json.h"

int free_comments_data(comments_data_t *data)
{
    if (data == NULL) {
        return JSON_ERROR;
    }
    free(data->user_uuid);
    free(data->reply_body);
    free(data->replied_time_str);
    free(data);
    return JSON_SUCCESS;
}
