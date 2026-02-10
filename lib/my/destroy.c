/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** destroy
*/

#include "my.h"

void destroy(window_t *data, game_sprites_t *game_data, ennemies_t *sp_data)
{
    sfSprite_destroy(sp_data->sprite);
    sfSprite_destroy(sp_data->sprite2);
    sfSprite_destroy(sp_data->sprite3);
    sfSprite_destroy(sp_data->sprite4);
    sfSprite_destroy(sp_data->sprite5);
    sfSprite_destroy(data->background);
    sfSprite_destroy(game_data->lose_sprite);
    sfSprite_destroy(game_data->win_sprite);
    sfClock_destroy(data->clock);
    sfClock_destroy(data->clock2);
    sfRenderWindow_destroy(data->window);
    sfTexture_destroy(sp_data->texture);
    sfTexture_destroy(data->texture2);
    sfTexture_destroy(game_data->texture6);
    sfTexture_destroy(game_data->texture4);
}
