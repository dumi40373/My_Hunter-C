/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** create_background
*/

#include "my.h"

sfSprite *create_sprite(sfTexture *texture, int x, int y)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_background(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.9375, 0.78125};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *create_game_over(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.5371, 0.5371};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){440, 136});
    return sprite;
}

sfSprite *create_win_game(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.5371, 0.5371};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){440, 136});
    return sprite;
}
