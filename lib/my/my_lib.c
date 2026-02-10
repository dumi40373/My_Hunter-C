/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** my_lib
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] != s1[i])
            return 0;
    }
    return 1;
}

void my_new_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
