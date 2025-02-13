/*
** EPITECH PROJECT, 2024
** teams
** File description:
** linked_list
*/

#pragma once

// An enum which contains every type of the program
typedef enum data_type_e {
    // Structures

    LINKED_LIST,
    DICT,
    TEAMS,
    CHANNELS,
    THREADS,
    COMMENTS,
    USERS,
    DIRECT_MESSAGE,
    MESSAGES,

    // Known types

    INT,
    INT_ARRAY,
    SIZE_T,
    CHAR,
    STRING,
    STRING_ARRAY,

    // Empty (if you need a spot for later)
    EMPTY,

    // Unknown

    UNKNOWN
} data_type_t;

/**
** @brief The generic linked list of the program
** @param index Index of the list
** @param data Variable that can contain a reference to anything
** @param type Type of the data variable
** @param prev A reference to the previous index of the list
** @param next A reference to the next index of the list
**/
struct linked_list_s {
    int index;
    void *data;
    data_type_t type;
    struct linked_list_s *prev;
    struct linked_list_s *next;
};

typedef struct linked_list_s linked_list_t;
typedef struct linked_list_s llist_t;

// The type to use in the code for the Epitech coding style
typedef struct linked_list_s ll_t;
