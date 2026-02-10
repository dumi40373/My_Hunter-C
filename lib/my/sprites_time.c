/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** sprites_time
*/

#include "my.h"

void set_sprites_time(window_t *data, ennemies_t *sp_data)
{
    sfTime t = sfClock_getElapsedTime(data->clock2);
    float sec = t.microseconds / 1000000.0f;

    if (sec > 2.0f && sp_data->sprite_count <= 5) {
        sp_data->sprite_count++;
        sfClock_restart(data->clock2);
    }
}

void draw_sprites(window_t *data, ennemies_t *sp_data)
{
    if (sp_data->sprite_count >= 1)
        sfRenderWindow_drawSprite(data->window, sp_data->sprite, NULL);
    if (sp_data->sprite_count >= 2)
        sfRenderWindow_drawSprite(data->window, sp_data->sprite2, NULL);
    if (sp_data->sprite_count >= 3)
        sfRenderWindow_drawSprite(data->window, sp_data->sprite3, NULL);
    if (sp_data->sprite_count >= 4)
        sfRenderWindow_drawSprite(data->window, sp_data->sprite4, NULL);
    if (sp_data->sprite_count >= 5)
        sfRenderWindow_drawSprite(data->window, sp_data->sprite5, NULL);
}
