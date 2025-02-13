/*
** EPITECH PROJECT, 2024
** server
** File description:
** server
*/

#pragma once

#include "server/struct.h"

// Server launch functions

int handle_server_error(int ac, char **av);
int init_server(server_t *server, char *str);
void server_loop(server_t *server);

// Client management functions

connected_t *init_client_list(void);
void add_new_client(connected_t *client, const int fd);
int get_client(connected_t *client, const int fd);
void send_to_client(connected_t client, const char *msg);
void delete_client(connected_t *client, const int fd);
void delete_all_client(connected_t *client);

// Command handling

void command_handling(connected_t *client, server_t *server, int i);
void do_command(connected_t *client, server_t *server, char **array, int got);

// Command list

void login(connected_t *client, server_t *server, char **array, int got);
void logout(connected_t *client, server_t *server, char **array, int got);
void users(connected_t *client, server_t *server, char **array, int got);
void help(connected_t *client, char **array, int got);
void user(connected_t *client, server_t *server, char **array, int got);
void send_msg(connected_t *client, server_t *server, char **array, int got);
void messages(connected_t *client, server_t *server, char **arr, int got);

// Command utils

void *finder(ll_t *list, const char *data, bool is_login);
void send_client_uuid_error(connected_t client, char *data);
