/*
** EPITECH PROJECT, 2024
** myTeams
** File description:
** start_loop
*/

#include <signal.h>

#include "constants.h"
#include "client/client.h"

static void handle_sigint(int sig)
{
    (void)sig;
}

static int handle_user_input(int sfd)
{
    char input[MAX_BUFFER_SIZE];
    ssize_t bytes_read = 0;

    memset(input, '\0', MAX_BUFFER_SIZE);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Failed to get user input.\n");
        return FUNC_ERROR;
    }
    bytes_read = send(sfd, input, strlen(input), 0);
    if (bytes_read == -1) {
        printf("Failed to send message to server.\n");
        return FUNC_ERROR;
    }
    return SUCCESS;
}

static int check_is_set(client_t *client)
{
    if (FD_ISSET(STDIN_FILENO, &client->ready_fd)) {
        if (handle_user_input(client->sfd) == FUNC_ERROR) {
            return FUNC_ERROR;
        }
    }
    if (FD_ISSET(client->sfd, &client->ready_fd)) {
        if (read_from_socket(client) == FUNC_ERROR) {
            return FUNC_ERROR;
        }
    }
    return SUCCESS;
}

static int client_loop(client_t *client)
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);
    FD_ZERO(&client->current_fd);
    FD_SET(STDIN_FILENO, &client->current_fd);
    FD_SET(client->sfd, &client->current_fd);
    while (727) {
        client->ready_fd = client->current_fd;
        if (select(FD_SETSIZE, &client->ready_fd, NULL, NULL, NULL) == -1) {
            printf("Shutdown client emergency activated.\n");
            break;
        }
        if (check_is_set(client) == FUNC_ERROR) {
            return FUNC_ERROR;
        }
    }
    return SUCCESS;
}

int start_client(const char *server_ip, int port)
{
    client_t client;

    client.sfd = create_socket();
    if (client.sfd == FUNC_ERROR) {
        return FUNC_ERROR;
    }
    if (connect_to_server(client.sfd, server_ip, port) == FUNC_ERROR) {
        return FUNC_ERROR;
    }
    if (client_loop(&client) == FUNC_ERROR) {
        shutdown(client.sfd, SHUT_RDWR);
        close(client.sfd);
        return FUNC_ERROR;
    }
    shutdown(client.sfd, SHUT_RDWR);
    close(client.sfd);
    return SUCCESS;
}
