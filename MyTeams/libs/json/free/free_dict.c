/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** free_dict.c
*/

#include <stdlib.h>
#include "json.h"

int free_dict(dict_t *content)
{
    int status = JSON_SUCCESS;

    if (content == NULL) {
        return JSON_ERROR;
    }
    free(content->term);
    status = free_node_content((json_t *)content->definition, content->type);
    if (status == JSON_SUCCESS) {
        free(content);
    }
    return status;
}
