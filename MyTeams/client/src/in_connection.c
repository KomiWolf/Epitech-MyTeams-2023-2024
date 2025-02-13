/*
** EPITECH PROJECT, 2024
** myTeams
** File description:
** in_connection
*/

#include "constants.h"
#include "client/client.h"

int connect_to_server(int sfd, const char *server_ip, int port)
{
    struct sockaddr_in s_addr;

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &s_addr.sin_addr) <= 0) {
        printf("Failed to convert to Internet number");
        shutdown(sfd, SHUT_RDWR);
        close(sfd);
        return FUNC_ERROR;
    }
    if (connect(sfd, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
        printf("Failed to connect to the server.\n");
        shutdown(sfd, SHUT_RDWR);
        close(sfd);
        return FUNC_ERROR;
    }
    return SUCCESS;
}
