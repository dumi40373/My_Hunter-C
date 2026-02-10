/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** create rect
*/

#include "my.h"

sfIntRect create_rect(void)
{
    sfIntRect rect = {0, 0, 110, 110};

    return rect;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}
