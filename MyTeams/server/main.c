/*
** EPITECH PROJECT, 2024
** server
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <malloc.h>

#include "json.h"
#include "constants.h"
#include "server/server.h"

static int display_helper(void)
{
    puts("USAGE: ./myteams_server port\n");
    puts("\tport\tis the port number on which the server socket listens.");
    return SUCCESS;
}

static void close_server(server_t *server)
{
    char *content = to_string(server->users);
    int fd = 0;

    if (content != NULL) {
        fd = open("./server/save/save_user.json",
        O_CREAT | O_TRUNC | O_WRONLY, 0644);
        if (fd != -1) {
            write(fd, content, strlen(content));
        }
        free(content);
        close(fd);
    }
    free_json(server->users);
    free_json(server->teams);
    shutdown(server->socket, SHUT_RDWR);
    close(server->socket);
}

int main(int ac, char **av)
{
    server_t server;

    if (ac == 2 &&
    (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0)) {
        return display_helper();
    }
    if (handle_server_error(ac, av) == FUNC_ERROR) {
        return ERROR;
    }
    if (init_server(&server, av[1]) == FUNC_ERROR) {
        return ERROR;
    }
    server_loop(&server);
    close_server(&server);
    return SUCCESS;
}
