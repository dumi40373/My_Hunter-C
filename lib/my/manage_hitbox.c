/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** create sprite
*/

#include "my.h"

void create_hitbox(sfRenderWindow *my_window, sfSprite *sprite,
    sfVector2f *speed)
{
    sfVector2u win = sfRenderWindow_getSize(my_window);
    sfFloatRect box;
    sfVector2f scale;

    sfSprite_move(sprite, *speed);
    box = sfSprite_getGlobalBounds(sprite);
    if (box.left < 0 || box.left + box.width > win.x) {
        speed->x = -speed->x;
        scale = sfSprite_getScale(sprite);
        scale.x = -scale.x;
        sfSprite_setScale(sprite, scale);
        box = sfSprite_getGlobalBounds(sprite);
    }
    if (box.top < 0 || box.top + box.height > (win.y * 0.8)) {
        speed->y = -speed->y;
        box = sfSprite_getGlobalBounds(sprite);
    }
}

void move_sprite(sfRenderWindow *my_window, ennemies_t *sp_data)
{
    create_hitbox(my_window, sp_data->sprite, &sp_data->speed);
    create_hitbox(my_window, sp_data->sprite2, &sp_data->speed2);
    create_hitbox(my_window, sp_data->sprite3, &sp_data->speed3);
    create_hitbox(my_window, sp_data->sprite4, &sp_data->speed4);
    create_hitbox(my_window, sp_data->sprite5, &sp_data->speed5);
    sfSleep(sfMilliseconds(60));
}
