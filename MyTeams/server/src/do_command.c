/*
** EPITECH PROJECT, 2024
** teams
** File description:
** do_command
*/

#include <unistd.h>
#include <malloc.h>
#include <string.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"

static bool do_command_2(connected_t *cli, server_t *svr, char **array, int g)
{
    if (strcmp(array[0], "/help") == 0) {
        help(cli, array, g);
        return true;
    }
    if (strcmp(array[0], "/user") == 0) {
        user(cli, svr, array, g);
        return true;
    }
    if (strcmp(array[0], "/send") == 0) {
        send_msg(cli, svr, array, g);
        return true;
    }
    if (strcmp(array[0], "/messages") == 0) {
        messages(cli, svr, array, g);
        return true;
    }
    return false;
}

void do_command(connected_t *client, server_t *server, char **array, int got)
{
    bool is_known_command = false;

    if (strcmp(array[0], "/login") == 0) {
        is_known_command = true;
        login(client, server, array, got);
    }
    if (strcmp(array[0], "/logout") == 0) {
        is_known_command = true;
        logout(client, server, array, got);
    }
    if (strcmp(array[0], "/users") == 0) {
        is_known_command = true;
        users(client, server, array, got);
    }
    if (is_known_command == false) {
        is_known_command = do_command_2(client, server, array, got);
        if (is_known_command == false) {
            send_to_client(client[got], COMMAND_UNKNOWN);
        }
    }
}
