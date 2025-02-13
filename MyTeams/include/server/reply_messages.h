/*
** EPITECH PROJECT, 2024
** teams
** File description:
** reply_messages
*/

#pragma once

// The file that contains every reply messages for the server
// to send to the client

// Success messages

#define NEW_CONNECTION "201 \"Client connected to server successfully\"\r\n"
#define HELP_OK "202 \"List every supported command: "
#define LOGIN_OK "203 \"User logged in successfully\" "
#define LOGOUT_OK "204 \"User logged out successfully\" "
#define USERS_OK "205 \"User list fetched successfully\" "
#define USER_OK "206 \"User information fetched successfully\" "
#define SEND_SENDER_OK "207 \"Message sended successfully\" "
#define SEND_RECEIVER_OK "208 \"A message has been received\" "
#define MESSAGES_OK "209 \"Messages with "

// Error messages

#define COMMAND_UNKNOWN "401 \"Command unknow\"\r\n"
#define NOT_CONNECTED "402 \"Login before using any commands\"\r\n"
#define PARAMETER_TOO_LOW "403 \"Parameter not set or too low\"\r\n"
#define PARAMETER_PARSING_ERROR "404 \"Parameter cannot be parsed\"\r\n"
#define TOO_MANY_PARAMETER "405 \"Too many parameters\"\r\n"
#define PARAMETER_TOO_LONG "406 \"Parameter too long\"\r\n"
#define USER_UUID_ERROR "407 \"User uuid given does not exist\" "
#define ALREADY_LOGGED "408 \"User already logged\"\r\n"
#define INTERNAL_SERVER_ERROR "409 \"Internal server error\"\r\n"
