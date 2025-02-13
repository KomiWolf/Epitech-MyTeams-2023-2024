/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** read_message
*/

#include "constants.h"
#include "client/client.h"
#include "utils.h"
#include "../libs/myteams/logging_client.h"

static void free_words(char **words)
{
    for (int i = 0; words[i] != NULL; i++)
        free(words[i]);
    free(words);
}

static int read_message(client_t *client)
{
    char **words = special_str_to_word_array(client->command);

    if (words == NULL) {
        printf("Error parsing command from server.\n");
        return FUNC_ERROR;
    }
    print_server_message((const char **)words);
    free_words(words);
    return SUCCESS;
}

int read_from_socket(client_t *client)
{
    ssize_t bytes_read = 0;

    memset(client->command, '\0', MAX_BUFFER_SIZE);
    bytes_read = read(client->sfd, client->command, sizeof(client->command));
    if (bytes_read == -1 || bytes_read == 0) {
        printf("Cannot read the server anymore.\n");
        return FUNC_ERROR;
    }
    read_message(client);
    return SUCCESS;
}
