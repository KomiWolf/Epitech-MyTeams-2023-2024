/*
** EPITECH PROJECT, 2024
** teams
** File description:
** struct
*/

#pragma once

#include <sys/select.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"

/**
** @brief Structure to store users data
** @param uuid Uuid of the user
** @param name Name of the user
** @param teams_uuid List of team in which the user is
** @param dm List of dm the user has
**/
typedef struct users_data_s {
    char *uuid;
    char *name;
    ll_t *teams_uuid;
    ll_t *dm;
} users_data_t;

/**
** @brief Structure to store users direct messages
** @param receiver_uuid Uuid of the message receiver
** @param messages List of every message of the sender and receiver
**/
typedef struct direct_message_s {
    char *receiver_uuid;
    ll_t *messages;
} direct_message_t;

/**
** @brief Structure to store messages
** @param msg Message body
** @param sender_uuid Uuid of the message sender
** @param sent_time Time of the sent message
** @param sent_time_str String version of the time of the sent message
**/
typedef struct messages_s {
    char *msg;
    char *sender_uuid;
    time_t sent_time;
    char *sent_time_str;
} messages_t;

/**
** @brief Structure to store teams data
** @param uuid Team uuid
** @param name Team name
** @param description Team description
** @param channels List of team channels
**/
typedef struct teams_data_s {
    char *uuid;
    char *name;
    char *description;
    ll_t *channels;
} teams_data_t;

/**
** @brief Structure to store channels data
** @param uuid Channel uuid
** @param name Channel name
** @param description Channel description
** @param channels List of channel threads
**/
typedef struct channels_data_s {
    char *uuid;
    char *name;
    char *description;
    ll_t *threads;
} channels_data_t;

/**
** @brief Structure to store threads data
** @param uuid Thread uuid
** @param user_uuid Uuid of the user who created the thread
** @param body Thread body
** @param created_time Creation time of the thread
** @param created_time_str String version of creation time
** @param comments List of comments threads
**/
typedef struct threads_data_s {
    char *uuid;
    char *user_uuid;
    char *title;
    char *body;
    time_t created_time;
    char *created_time_str;
    ll_t *comments;
} threads_data_t;

/**
** @brief Structure to store comments data
** @param user_uuid Uuid of the user who replied to the thread
** @param reply_body Reply body
** @param replied_time Replied time of the comment
** @param replied_time_str String version of replied time
**/
typedef struct comments_data_s {
    char *user_uuid;
    char *reply_body;
    time_t replied_time;
    char *replied_time_str;
} comments_data_t;

/**
** @brief All data stored in the server
** @param socket Socket of the server
** @param current_fd List of every client fd
** @param ready_fd List of every client to use for select
** @param users List of data of every users
** @param teams List of data of every teams
**/
typedef struct server_s {
    int socket;
    fd_set current_fd;
    fd_set ready_fd;
    ll_t *users;
    ll_t *teams;
} server_t;

/**
** @brief Structure array of connected user on the server
** @param fd The file descriptor of the connected client in the server
** @param is_login Checker to verify if the connected client is authentificated
** @param user_uuid The uuid of the connected client in the server
**/
typedef struct connected_s {
    int fd;
    bool is_login;
    char *user_uuid;
    char *user_name;
} connected_t;

/**
** @brief Structure to represent a dictionnary node
** @param term Name of the data
** @param definition Data (It can take anything)
** @param type Type of the data
**/
typedef struct dict_s {
    char *term;
    void *definition;
    data_type_t type;
} dict_t;
