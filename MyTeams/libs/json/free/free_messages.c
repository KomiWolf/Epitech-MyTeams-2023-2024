/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_messages.c
*/

#include <stdlib.h>
#include "json.h"

int free_messages(messages_t *data)
{
    if (data == NULL) {
        return JSON_ERROR;
    }
    free(data->msg);
    free(data->sender_uuid);
    free(data->sent_time_str);
    free(data);
    return JSON_SUCCESS;
}
