/*
** EPITECH PROJECT, 2024
** teams
** File description:
** use_log_function
*/

#include <dlfcn.h>
#include <stdarg.h>
#include <malloc.h>
#include <string.h>

#include "constants.h"
#include "json.h"

int (*log_function)(char const *param1, ...);

static void fill_index(char **array, char *str, int count)
{
    if (str != NULL) {
        array[count] = strdup(str);
    } else {
        array[count] = strdup("");
    }
}

static char **get_args(const char *format, va_list list, int *count)
{
    char **array = malloc(sizeof(char *) * 6);
    char *str = NULL;

    for (size_t i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 's') {
            str = va_arg(list, char *);
            fill_index(array, str, *count);
            (*count)++;
            i++;
        }
    }
    array[*count] = NULL;
    return array;
}

void which_log_function(char **array, int c, void *handle, const char *name)
{
    log_function = dlsym(handle, name);
    switch (c) {
        case 1:
            log_function(array[0]);
            break;
        case 2:
            log_function(array[0], array[1]);
            break;
        case 3:
            log_function(array[0], array[1], array[2]);
            break;
        case 4:
            log_function(array[0], array[1], array[2], array[3]);
            break;
        case 5:
            log_function(array[0], array[1], array[2], array[3], array[4]);
            break;
        default:
            break;
    }
}

int use_log_function(const char *log_function_name, const char *format, ...)
{
    void *handle = dlopen("./libs/myteam/libmyteams.so", RTLD_LAZY);
    va_list list;
    int count = 0;
    char **array = NULL;

    va_start(list, format);
    array = get_args(format, list, &count);
    va_end(list);
    which_log_function(array, count, handle, log_function_name);
    free_string_array(array);
    dlclose(handle);
    return SUCCESS;
}
