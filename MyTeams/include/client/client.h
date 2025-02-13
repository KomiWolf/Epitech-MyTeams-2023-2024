/*
** EPITECH PROJECT, 2024
** teams
** File description:
** client
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "client/struct.h"

int read_from_socket(client_t *client);

void print_server_message(const char **words);

int handle_client_error(int ac, char **av);
int connect_to_server(int sfd, const char *server_ip, int port);
int create_socket(void);
int start_client(const char *server_ip, int port);
