/*
** EPITECH PROJECT, 2024
** teams
** File description:
** time_handling
*/

#include <time.h>
#include <malloc.h>

#include "constants.h"

time_t get_time(void)
{
    time_t t = time(NULL);

    if (t == FUNC_ERROR) {
        printf("Error: Failed to get time.");
        return FUNC_ERROR;
    }
    return t;
}

char *time_to_string(time_t data)
{
    char *time_str = malloc(sizeof(char) * MAX_BUFFER_SIZE);

    sprintf(time_str, "%lld", (long long)data);
    return time_str;
}

time_t string_to_time(char *time_str)
{
    time_t t = 0;

    for (size_t i = 0; time_str[i] != '\0'; i++) {
        t += time_str[i] - 48;
        if (time_str[i + 1] == '\0') {
            continue;
        } else {
            t *= 10;
        }
    }
    return t;
}
