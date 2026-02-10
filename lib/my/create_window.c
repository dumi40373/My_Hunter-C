/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** create window
*/

#include "my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1440, 800, 32};
    sfUint32 style = {sfClose | sfResize};
    sfRenderWindow *my_window;

    my_window = sfRenderWindow_create(mode, "my_hunter", style, NULL);
    return my_window;
}
