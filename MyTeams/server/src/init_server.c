/*
** EPITECH PROJECT, 2024
** teams
** File description:
** init_server
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "json.h"
#include "constants.h"
#include "server/server.h"

static int set_up_server(server_t *server, int port)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        shutdown(server->socket, SHUT_RDWR);
        printf("Failed to bind the server to a local address.\n");
        free(server->users);
        free(server->teams);
        return FUNC_ERROR;
    }
    if (listen(server->socket, MAX_CONNECTED_CLIENT) == FUNC_ERROR) {
        shutdown(server->socket, SHUT_RDWR);
        printf("Listen error.\n");
        free(server->users);
        free(server->teams);
        return FUNC_ERROR;
    }
    return SUCCESS;
}

int init_server(server_t *server, char *str)
{
    int port = atoi(str);

    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == FUNC_ERROR) {
        printf("Failed to create a socket for the server.\n");
        return FUNC_ERROR;
    }
    server->teams = init_json(NULL, EMPTY);
    server->users = init_json(NULL, EMPTY);
    return set_up_server(server, port);
}
