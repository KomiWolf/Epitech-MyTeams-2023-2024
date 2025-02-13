/*
** EPITECH PROJECT, 2024
** teams
** File description:
** command_handling
*/

#include <unistd.h>
#include <malloc.h>
#include <string.h>

#include "json.h"
#include "utils.h"
#include "constants.h"
#include "server/server.h"
#include "server/reply_messages.h"
#include "../../libs/myteams/logging_server.h"

static void launch_command(connected_t *cli, server_t *svr, char *str, int got)
{
    char **parsed_command = special_str_to_word_array(str);

    if (parsed_command == NULL) {
        send_to_client(cli[got], PARAMETER_PARSING_ERROR);
        return;
    }
    do_command(cli, svr, parsed_command, got);
    free_string_array(parsed_command);
}

static void read_error(const ssize_t read_bytes, connected_t client)
{
    char reply[MAX_BUFFER_SIZE];

    memset(reply, '\0', MAX_BUFFER_SIZE);
    strcpy(reply, LOGOUT_OK);
    strcat(reply, "\"");
    if (client.user_uuid != NULL) {
        strcat(reply, client.user_uuid);
    }
    strcat(reply, "\" \"");
    if (client.user_name != NULL) {
        strcat(reply, client.user_name);
    }
    strcat(reply, "\"\r\n");
    if (read_bytes <= 0) {
        server_event_user_logged_out(client.user_uuid);
        send_to_client(client, reply);
    }
}

void command_handling(connected_t *client, server_t *server, int i)
{
    char buffer[MAX_BUFFER_SIZE];
    ssize_t read_bytes = 0;
    int got = get_client(client, i);

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    read_bytes = read(i, buffer, sizeof(buffer));
    if (read_bytes <= 0) {
        read_error(read_bytes, client[got]);
        FD_CLR(i, &server->current_fd);
        delete_client(client, i);
    } else if (read_bytes >= MAX_BUFFER_SIZE) {
        return;
    } else {
        launch_command(client, server, buffer, got);
    }
}
