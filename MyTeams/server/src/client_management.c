/*
** EPITECH PROJECT, 2024
** teams
** File description:
** client_management
*/

#include <malloc.h>
#include <unistd.h>
#include <string.h>

#include "server/struct.h"
#include "constants.h"

connected_t *init_client_list(void)
{
    connected_t *clients = malloc(sizeof(connected_t) * MAX_CONNECTED_CLIENT);

    for (int i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        clients[i].fd = UNKNOW;
        clients[i].is_login = false;
        clients[i].user_uuid = NULL;
        clients[i].user_name = NULL;
    }
    return clients;
}

void add_new_client(connected_t *client, const int fd)
{
    for (int i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].fd == UNKNOW) {
            client[i].fd = fd;
            return;
        }
    }
}

int get_client(connected_t *client, const int fd)
{
    for (int i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].fd == fd) {
            return i;
        }
    }
    return UNKNOW;
}

static void free_string(connected_t *client, const int index)
{
    if (client[index].user_uuid != NULL) {
        free(client[index].user_uuid);
        client[index].user_uuid = NULL;
    }
    if (client[index].user_name != NULL) {
        free(client[index].user_name);
        client[index].user_name = NULL;
    }
}

void delete_client(connected_t *client, const int fd)
{
    for (int i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].fd == fd) {
            close(client[i].fd);
            client[i].fd = UNKNOW;
            client[i].is_login = false;
            free_string(client, i);
        }
    }
}

void delete_all_client(connected_t *client)
{
    for (int i = 0; i < MAX_CONNECTED_CLIENT; i++) {
        if (client[i].fd != UNKNOW) {
            close(client[i].fd);
            client[i].fd = UNKNOW;
            client[i].is_login = false;
            free_string(client, i);
        }
    }
    free(client);
}
