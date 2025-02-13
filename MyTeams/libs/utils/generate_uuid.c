/*
** EPITECH PROJECT, 2024
** teams
** File description:
** generate_uuid
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

static void insert_letter(char *uuid_str)
{
    int index = 0;

    for (size_t i = 0; i < 14; i++) {
        index = rand() % 31;
        if (uuid_str[index] >= 'a' && uuid_str[index] <= 'z') {
            i--;
            continue;
        }
        uuid_str[index] += 49;
    }
}

char *generate_uuid(void)
{
    int data_1[2];
    long long int res1 = (long long int) data_1;
    int data_2[2];
    int data_3[2];
    long long int res2 = (long long int) data_2;
    long long int res3 = (long long int) data_3;
    char rand_str[(sizeof(long long int) * 3)+1];
    char *uuid_str = malloc(sizeof(char) * 33);

    if (uuid_str == NULL) {
        return NULL;
    }
    srand(time(NULL));
    memset(uuid_str, '\0', (sizeof(char) * 33));
    sprintf(rand_str, "%lld%lld%lld", res1, res2, res3);
    strncpy(uuid_str, rand_str, 32);
    uuid_str[32] = '\0';
    insert_letter(uuid_str);
    return uuid_str;
}
