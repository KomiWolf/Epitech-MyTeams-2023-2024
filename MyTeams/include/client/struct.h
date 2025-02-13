/*
** EPITECH PROJECT, 2024
** teams
** File description:
** struct
*/

#pragma once

#include <sys/select.h>

#include "constants.h"

typedef struct client_s {
    int sfd;
    char command[MAX_BUFFER_SIZE];
    fd_set current_fd;
    fd_set ready_fd;
} client_t;
