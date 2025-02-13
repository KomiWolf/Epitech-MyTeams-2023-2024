/*
** EPITECH PROJECT, 2024
** teams
** File description:
** server_loop
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#include "server/server.h"
#include "server/reply_messages.h"
#include "constants.h"

static void handle_sigint(int sig)
{
    (void)sig;
}

static int connection_handling(connected_t *client, server_t *server, int i)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int client_fd = 0;

    if (i == server->socket) {
        client_fd = accept(server->socket, (struct sockaddr *)&addr, &len);
        if (client_fd == -1) {
            printf("Failed to get connexion with the client.\n");
            return ERROR;
        }
        FD_SET(client_fd, &server->current_fd);
        add_new_client(client, client_fd);
        write(client_fd, NEW_CONNECTION, strlen(NEW_CONNECTION));
        printf("Connexion from %s:%d\n", inet_ntoa(addr.sin_addr),
        ntohs(addr.sin_port));
        return SUCCESS;
    }
    command_handling(client, server, i);
    return SUCCESS;
}

static int fd_loop_statement(connected_t *client, server_t *server, int i)
{
    if (FD_ISSET(i, &server->ready_fd)) {
        if (connection_handling(client, server, i) == ERROR) {
            return ERROR;
        }
    }
    return SUCCESS;
}

static int loop_in_fd(connected_t *client, server_t *server)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (fd_loop_statement(client, server, i) == ERROR) {
            return ERROR;
        }
    }
    return SUCCESS;
}

void server_loop(server_t *server)
{
    connected_t *client = init_client_list();
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);
    FD_ZERO(&server->current_fd);
    FD_SET(server->socket, &server->current_fd);
    while (true) {
        server->ready_fd = server->current_fd;
        if (select(FD_SETSIZE, &server->ready_fd, NULL, NULL, NULL) < 0) {
            printf("Shutdown server emergency activated.\n");
            delete_all_client(client);
            break;
        }
        if (loop_in_fd(client, server) == ERROR) {
            return;
        }
    }
}
