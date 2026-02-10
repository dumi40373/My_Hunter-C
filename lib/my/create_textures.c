/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** creates_texture
*/

#include "my.h"

sfTexture *create_texture(void)
{
    sfTexture *texture;
    char *image_path = "duck_spritesheet.png";

    texture = sfTexture_createFromFile(image_path, NULL);
    return texture;
}

sfTexture *create_texture2(void)
{
    sfTexture *texture;
    char *image_path = "windows_wp_game.png";

    texture = sfTexture_createFromFile(image_path, NULL);
    return texture;
}

sfTexture *create_texture3(void)
{
    sfTexture *texture;
    char *image_path = "game_over.png";

    texture = sfTexture_createFromFile(image_path, NULL);
    return texture;
}

sfTexture *create_texture4(void)
{
    sfTexture *texture;
    char *image_path = "won_sprite.png";

    texture = sfTexture_createFromFile(image_path, NULL);
    return texture;
}
