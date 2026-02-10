/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** execute
*/

#include "my.h"

void open_window_3(window_t *data, ennemies_t *sp_data,
    game_sprites_t *game_data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawSprite(data->window, data->background, NULL);
    if (lose_case(game_data)) {
        manage_lose(data, game_data);
        return;
    }
    if (win_case(game_data)) {
        manage_win(data, game_data);
        return;
    }
    move_sprite(data->window, sp_data);
    sfSprite_setTextureRect(sp_data->sprite, data->rect);
    sfSprite_setTextureRect(sp_data->sprite2, data->rect);
    sfSprite_setTextureRect(sp_data->sprite3, data->rect);
    sfSprite_setTextureRect(sp_data->sprite4, data->rect);
    sfSprite_setTextureRect(sp_data->sprite5, data->rect);
    set_sprites_time(data, sp_data);
    draw_sprites(data, sp_data);
    sfRenderWindow_display(data->window);
}

void open_window_2(window_t *data, ennemies_t *sp_data,
    game_sprites_t *game_data)
{
    sfTime time = sfClock_getElapsedTime(data->clock);
    float seconds = time.microseconds / 150000.0f;

    if (seconds > 1.0f) {
        move_rect(&data->rect, 110, 330);
        sfClock_restart(data->clock);
    }
    open_window_3(data, sp_data, game_data);
}

void open_window(ennemies_t *sp_data, window_t *data, game_sprites_t *game_data)
{
    sfEvent event;
    sfIntRect rect2 = {0, 0, 110, 110};

    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window)) {
        while (sfRenderWindow_pollEvent(data->window, &event)) {
            analyse_events(&event, sp_data, data, game_data);
        }
        open_window_2(data, sp_data, game_data);
    }
    destroy(data, game_data, sp_data);
}

void window_struct(ennemies_t *sp_data, sfTexture *texture2,
    sfTexture *texture3, sfTexture *texture4)
{
    window_t data = {
        .window = create_window(),
        .background = create_background(texture2),
        .clock = sfClock_create(),
        .rect = create_rect(),
        .clock2 = sfClock_create(),
        .texture2 = texture2
    };
    game_sprites_t game_data = {
        .clicks_count = 0,
        .lose_sprite = create_game_over(texture3),
        .lost = 0,
        .win_count = 0,
        .win = 0,
        .win_sprite = create_win_game(texture4),
        .texture6 = texture3,
        .texture4 = texture4
    };

    open_window(sp_data, &data, &game_data);
}

void execute_window(void)
{
    sfTexture *texture = create_texture();
    ennemies_t sp_data = {
        .sprite = create_sprite(texture, rand() % 799, rand() % 369),
        .speed = {12 + rand() % (30 - 12), 8 + rand() % (15 - 8)},
        .sprite2 = create_sprite(texture, rand() % 799, rand() % 369),
        .speed2 = {12 + rand() % (30 - 12), 8 + rand() % (15 - 8)},
        .sprite3 = create_sprite(texture, rand() % 799, rand() % 369),
        .speed3 = {12 + rand() % (30 - 12), 8 + rand() % (15 - 8)},
        .sprite4 = create_sprite(texture, rand() % 799, rand() % 369),
        .speed4 = {12 + rand() % (30 - 12), 8 + rand() % (15 - 8)},
        .sprite5 = create_sprite(texture, rand() % 799, rand() % 369),
        .speed5 = {12 + rand() % (30 - 12), 8 + rand() % (15 - 8)},
        .sprite_count = 1,
        .texture = texture
    };
    sfTexture *texture2 = create_texture2();
    sfTexture *texture3 = create_texture3();
    sfTexture *texture4 = create_texture4();
    sfVector2f scale = {1.12, 1.12};
    window_struct(&sp_data, texture2, texture3, texture4);
}
