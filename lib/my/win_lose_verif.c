/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** win lose verif
*/
#include "my.h"

int lose_case(game_sprites_t *game_data)
{
    if (game_data->lost == 1)
        return 1;
    return 0;
}

int win_case(game_sprites_t *game_data)
{
    if (game_data->win == 1)
        return 1;
    return 0;
}

void manage_lose(window_t *data, game_sprites_t *game_data)
{
    sfRenderWindow_drawSprite(data->window, game_data->lose_sprite, NULL);
    sfRenderWindow_display(data->window);
}

void manage_win(window_t *data, game_sprites_t *game_data)
{
    sfRenderWindow_drawSprite(data->window, game_data->win_sprite, NULL);
    sfRenderWindow_display(data->window);
}
