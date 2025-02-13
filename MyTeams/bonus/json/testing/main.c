/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** tmp.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include "json.h"

static char **create_string_array(unsigned int width, unsigned int height)
{
    unsigned int h = 0;
    unsigned int w = 0;
    char **data = malloc(sizeof(char *) * (height + 1));

    for (; h < height; h++) {
        data[h] = malloc(sizeof(char) * (width + 1));
        for (w = 0; w < width; w++) {
            data[h][w] = 'a';
        }
        data[h][w] = '\0';
    }
    data[h] = NULL;
    return data;
}

static int *create_int_array(unsigned int width)
{
    unsigned int w = 0;
    int *data = malloc(sizeof(int *) * width + 1);

    for (; w < width; w++) {
        data[w] = w;
    }
    data[w] = JSON_INT_ARRAY_END;
    return data;
}

static dict_t *create_dict()
{
    dict_t *data = malloc(sizeof(dict_t));

    if (data == NULL) {
        return NULL;
    }
    data->term = strdup("Term");
    data->definition = strdup("Definition");
    data->type = STRING;
    return data;
}

static teams_data_t *create_teams()
{
    teams_data_t *data = malloc(sizeof(teams_data_t));

    if (data == NULL) {
        return NULL;
    }
    data->channels = init_json(NULL, EMPTY);
    data->description = strdup("Description");
    data->name = strdup("Name");
    data->uuid = strdup("uuid");
    return data;
}

static channels_data_t *create_channels()
{
    channels_data_t *data = malloc(sizeof(channels_data_t));

    if (data == NULL) {
        return NULL;
    }
    data->description = strdup("description");
    data->name = strdup("name");
    data->uuid = strdup("uuid");
    data->threads = init_json(NULL, EMPTY);
    return data;
}

static threads_data_t *create_threads_data()
{
    threads_data_t *data = malloc(sizeof(threads_data_t));

    if (data == NULL) {
        return NULL;
    }
    data->body = strdup("body");
    data->comments = init_json(NULL, EMPTY);
    data->created_time = 0;
    data->created_time_str = strdup("created_time_str");
    data->title = strdup("title");
    data->user_uuid = strdup("user_uuid");
    data->uuid = strdup("uuid");
    return data;
}

static comments_data_t *create_comments()
{
    comments_data_t *data = malloc(sizeof(comments_data_t));

    if (data == NULL) {
        return NULL;
    }
    data->user_uuid = strdup("user_uuid");
    data->reply_body = strdup("reply_body");
    data->replied_time = 0;
    data->replied_time_str = strdup("replied_time_str");
    return data;
}

static users_data_t *create_users()
{
    users_data_t *data = malloc(sizeof(users_data_t));

    if (data == NULL) {
        return NULL;
    }
    data->dm = init_json(NULL, EMPTY);
    data->name = strdup("name");
    data->teams_uuid = init_json(NULL, EMPTY);
    data->uuid = strdup("uuid");
    return data;
}

static direct_message_t *create_direct_message()
{
    direct_message_t *data = malloc(sizeof(direct_message_t));

    if (data == NULL) {
        return NULL;
    }
    data->messages = init_json(NULL, EMPTY);
    data->receiver_uuid = strdup("receiver_uuid");
    return data;
}

static messages_t *create_messages()
{
    messages_t *data = malloc(sizeof(messages_t));

    if (data == NULL) {
        return NULL;
    }
    data->msg = strdup("msg");
    data->sender_uuid = strdup("sender_uuid");
    data->sent_time = 0;
    data->sent_time_str = strdup("sent_time_str");
    return data;
}

static void append_data(json_t *data, data_type_t type)
{
    switch (type) {
        case LINKED_LIST:
            append_linked_list(data, init_json(NULL, EMPTY));
            break;
        case DICT:
            append_dict(data, create_dict());
            break;
        case TEAMS:
            append_teams_data(data, create_teams());
            break;
        case CHANNELS:
            append_channels_data(data, create_channels());
            break;
        case THREADS:
            append_threads_data(data, create_threads_data());
            break;
        case COMMENTS:
            append_comments_data(data, create_comments());
            break;
        case USERS:
            append_users_data(data, create_users());
            break;
        case DIRECT_MESSAGE:
            append_direct_message(data, create_direct_message());
            break;
        case MESSAGES:
            append_messages(data, create_messages());
            break;
        case INT:
            append_int(data, 100);
            break;
        case INT_ARRAY:
            append_int_array(data, create_int_array(20));
            break;
        case SIZE_T:
            append_size_t(data, 200);
            break;
        case CHAR:
            append_char(data, 'a');
            break;
        case STRING:
            append_string(data, "This is a test string");
            break;
        case STRING_ARRAY:
            append_string_array(data, create_string_array(10, 10));
            break;
        case EMPTY:
            append_node(data, NULL, EMPTY);
            break;
        case UNKNOWN:
            append_node(data, NULL, UNKNOWN);
            break;
        default:
            append_node(data, NULL, EMPTY);
            break;
    }
}

static void build_json(json_t *data)
{
    append_data(data, INT); // Works
    // append_data(data, INT); // Works
    append_data(data, CHAR); // Works
    // append_data(data, CHAR); // Works
    append_data(data, DICT); // Fix incorrect memory readings
    // append_data(data, DICT); // Fix incorrect memory readings
    append_data(data, TEAMS); // No valgrind errors, Fix display
    // append_data(data, TEAMS); // No valgrind errors, Fix display
    append_data(data, USERS); // Fix display
    // append_data(data, USERS); // Fix display
    append_data(data, EMPTY); // Works
    // append_data(data, EMPTY); // Works
    append_data(data, SIZE_T); // Works
    // append_data(data, SIZE_T); // Works
    append_data(data, STRING); // Works
    // append_data(data, STRING); // Works
    // append_data(data, SERVER); // Ignored
    // append_data(data, SERVER); // Ignored
    append_data(data, UNKNOWN); // Works
    // append_data(data, UNKNOWN); // Works
    append_data(data, THREADS); // Fix display
    // append_data(data, THREADS); // Fix display
    append_data(data, CHANNELS); // Fix display
    // append_data(data, CHANNELS); // Fix display
    append_data(data, COMMENTS); // Fix display
    // append_data(data, COMMENTS); // Fix display
    append_data(data, MESSAGES); // Fix display
    // append_data(data, MESSAGES); // Fix display
    append_data(data, INT_ARRAY); // Works
    // append_data(data, INT_ARRAY); // Works
    // append_data(data, CONNECTED); // Ignored
    // append_data(data, CONNECTED); // Ignored
    append_data(data, STRING_ARRAY); // Works
    // append_data(data, STRING_ARRAY); // Works
    append_data(data, DIRECT_MESSAGE); // Fix display, Fix Crash
    // append_data(data, DIRECT_MESSAGE); // Fix display, Fix Crash
    printf("list_length = %d\n", get_list_size(data));
}

int main(void)
{
    char *conversion;
    char tmp[] = "jjijoojj";
    char *data1 = malloc(sizeof(char) * strlen(tmp) + 1);
    json_t *data;

    my_putstr("Variables initialised\n");
    strcpy(data1, tmp);
    my_putstr("String copied\n");
    data = init_json(data1, STRING);
    build_json(data);
    my_putstr("Json initialised\n");
    conversion = to_string(data);
    my_putstr("String converted\n");
    my_putstr("Converted data = '");
    my_putstr(conversion);
    my_putstr("'\n");
    my_putstr("Data displayed\n");
    free_json(data);
    my_putstr("Json freed\n");
    free(conversion);
    my_putstr("Conversion freed\n");
    return 0;
}
