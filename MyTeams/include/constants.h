/*
** EPITECH PROJECT, 2024
** teams
** File description:
** constants
*/

#pragma once

    //!! Return value !!//

    #define ERROR 84
    #define FUNC_ERROR -1
    #define SUCCESS 0

    //!! Value to use in code !!//

    #define MAX_UUID_LENGTH 32
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define MAX_BUFFER_SIZE 5000
    #define MAX_CONNECTED_CLIENT 1024
    #define UNKNOW -1
    #define NOT_CONNECTED_STATUS 0
    #define CONNECTED_STATUS 1

    //!! Constants for client side !!//

    // Argument error

    #define CLIENT_ARGS_NB_ERROR "Error: The program only handle 2 arguments."
    #define F_ARG_IS_NOT_IP "Error: The first argument must be an ip."
    #define S_ARG_IS_NOT_PORT "Error: The second argument must be a port."

    //!! Constants for server side !!//

    // Argument error

    #define SERVER_ARGS_NB_ERROR "Error: The program only handle 1 arguments."
    #define F_ARG_IS_NOT_PORT "Error: The first argument must be a port"
