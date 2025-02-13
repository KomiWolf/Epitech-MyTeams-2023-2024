/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_direct_message.c
*/

#include <stdlib.h>
#include "json.h"

int free_direct_message(direct_message_t *data)
{
    int status = JSON_SUCCESS;

    my_putdebug("(fdm) In free direct message\n");
    if (data == NULL) {
        my_putdebug("(fdm) data = NULL\n");
        return JSON_ERROR;
    }
    free(data->receiver_uuid);
    my_putdebug("(fdm) data->receiver_uuid freed\n");
    status = free_node_content((void *)data->messages, LINKED_LIST);
    if (status == JSON_SUCCESS) {
        free(data);
    }
    my_putdebug("(fdm) data->receiver_uuid freed\n");
    return status;
}
