/*
** EPITECH PROJECT, 2024
** teams
** File description:
** utils
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <time.h>

/**
** @brief A function to separate a string based on the separator
** @param str The string to separate
** @param sep The separator (It must be a character)
**/
char **str_to_word_array(const char *str, const char sep);

/**
** @brief A function to check if a string only contains digits
** @param str The string to check
**/
bool is_digit(const char *str);

/**
** @brief The generic function to parse the client and server message
** @param str The string to parse
** @return String array (char **): If parsed correctly
** @exception NULL: If the string cannot be parsed (Example: 3 double quotes)
**/
char **special_str_to_word_array(const char *str);

/**
** @brief The generic function to load and use the Epitech's log functions
** @param log_function_name The name of the log function we want to use
** @param format The format of the next parameters (%s)
** @param ... Any variables for the log functions
**/
int use_log_function(const char *log_function_name, const char *format, ...);

/**
** @brief A function to generate a uuid
**/
char *generate_uuid(void);

/**
** @brief A function to count an array length
** @param array The array to use
**/
size_t count_array_length(char **array);

time_t get_time(void);
char *time_to_string(time_t data);
time_t string_to_time(char *time_str);
