/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** call_log
*/

#include "constants.h"
#include "client/client.h"
#include "utils.h"
#include "../libs/myteams/logging_client.h"

static void users_loop(const char **words)
{
    for (int i = 3; words[i] != NULL; i += 4) {
        if (strcmp(words[i + 2], "on") == 0) {
            client_print_users(words[i], words[i + 1], CONNECTED_STATUS);
        } else {
            client_print_users(words[i], words[i + 1], NOT_CONNECTED_STATUS);
        }
        if (words[i + 3] == NULL) {
            return;
        }
    }
}

static void print_user(const char **words)
{
    if (strcmp(words[0], "205") == 0) {
        users_loop(words);
    }
    if (strcmp(words[0], "206") == 0) {
        if (strcmp(words[4], "on") == 0) {
            client_print_users(words[2], words[3], CONNECTED_STATUS);
        } else {
            client_print_users(words[2], words[3], NOT_CONNECTED_STATUS);
        }
    }
}

static void print_messages(const char **words)
{
    for (int i = 3; words[i] != NULL; i += 4) {
        client_private_message_print_messages(words[i],
        string_to_time((char *)words[i + 1]), words[i + 2]);
        if (words[i + 3] == NULL) {
            return;
        }
    }
}

static void call_log(const char **words)
{
    if (strcmp(words[0], "401") == 0 || strcmp(words[0], "402") == 0 ||
        strcmp(words[0], "403") == 0 || strcmp(words[0], "404") == 0 ||
        strcmp(words[0], "405") == 0 || strcmp(words[0], "406") == 0) {
        client_error_unauthorized();
    }
    if (strcmp(words[0], "407") == 0)
        client_error_unknown_user(words[2]);
    if (strcmp(words[0], "203") == 0)
        client_event_logged_in(words[2], words[3]);
    if (strcmp(words[0], "204") == 0)
        client_event_logged_out(words[2], words[3]);
    print_user(words);
    if (strcmp(words[0], "208") == 0)
        client_event_private_message_received(words[2], words[3]);
    if (strcmp(words[0], "209") == 0)
        print_messages(words);
}

void print_server_message(const char **words)
{
    char combined_message[MAX_BUFFER_SIZE];

    strcpy(combined_message, "Server said: ");
    for (int i = 0; words[i] != NULL; i++) {
        strcat(combined_message, words[i]);
        if (words[i + 1] != NULL)
            strcat(combined_message, "-");
    }
    if (strcmp(words[0], "201") == 0 || strcmp(words[0], "408") == 0 ||
        strcmp(words[0], "409") == 0 || strcmp(words[0], "207") == 0 ||
        strcmp(words[0], "202") == 0) {
        printf("%s\n", combined_message);
    } else {
        call_log(words);
    }
}
