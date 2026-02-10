/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** analyse events
*/

#include "my.h"

static void manage_mouse_click(sfMouseButtonEvent *event, ennemies_t *sp_data)
{
    sfFloatRect duck_pos = sfSprite_getGlobalBounds(sp_data->sprite);
    sfFloatRect duck_pos2 = sfSprite_getGlobalBounds(sp_data->sprite2);
    sfFloatRect duck_pos3 = sfSprite_getGlobalBounds(sp_data->sprite3);
    sfFloatRect duck_pos4 = sfSprite_getGlobalBounds(sp_data->sprite4);
    sfFloatRect duck_pos5 = sfSprite_getGlobalBounds(sp_data->sprite5);

    if (sfFloatRect_contains(&duck_pos, event->x, event->y))
        sfSprite_setPosition(sp_data->sprite, (sfVector2f){-9999, -9999});
    if (sfFloatRect_contains(&duck_pos2, event->x, event->y))
        sfSprite_setPosition(sp_data->sprite2, (sfVector2f){-9999, -9999});
    if (sfFloatRect_contains(&duck_pos3, event->x, event->y))
        sfSprite_setPosition(sp_data->sprite3, (sfVector2f){-9999, -9999});
    if (sfFloatRect_contains(&duck_pos4, event->x, event->y))
        sfSprite_setPosition(sp_data->sprite4, (sfVector2f){-9999, -9999});
    if (sfFloatRect_contains(&duck_pos5, event->x, event->y))
        sfSprite_setPosition(sp_data->sprite5, (sfVector2f){-9999, -9999});
}

static void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

int manage_losing_game(ennemies_t *sp_data, sfMouseButtonEvent *event)
{
    sfFloatRect duck_pos = sfSprite_getGlobalBounds(sp_data->sprite);
    sfFloatRect duck_pos2 = sfSprite_getGlobalBounds(sp_data->sprite2);
    sfFloatRect duck_pos3 = sfSprite_getGlobalBounds(sp_data->sprite3);
    sfFloatRect duck_pos4 = sfSprite_getGlobalBounds(sp_data->sprite4);
    sfFloatRect duck_pos5 = sfSprite_getGlobalBounds(sp_data->sprite5);

    if (sfFloatRect_contains(&duck_pos, event->x, event->y))
        return 0;
    if (sfFloatRect_contains(&duck_pos2, event->x, event->y))
        return 0;
    if (sfFloatRect_contains(&duck_pos3, event->x, event->y))
        return 0;
    if (sfFloatRect_contains(&duck_pos4, event->x, event->y))
        return 0;
    if (sfFloatRect_contains(&duck_pos5, event->x, event->y))
        return 0;
    return 1;
}

void restart_game2(ennemies_t *sp_data, window_t *data,
    game_sprites_t *game_data)
{
    game_data->clicks_count = 0;
    game_data->lost = 0;
    game_data->win = 0;
    game_data->win_count = 0;
    sfClock_restart(data->clock);
    sfClock_restart(data->clock2);
    data->rect = create_rect();
    sp_data->sprite_count = 1;
}

void restart_game(ennemies_t *sp_data, window_t *data,
    game_sprites_t *game_data)
{
    sfTexture *texture = create_texture();

    restart_game2(sp_data, data, game_data);
    sp_data->sprite = create_sprite(texture, rand() % 799, rand() % 369);
    sp_data->sprite2 = create_sprite(texture, rand() % 799, rand() % 369);
    sp_data->sprite3 = create_sprite(texture, rand() % 799, rand() % 369);
    sp_data->sprite4 = create_sprite(texture, rand() % 799, rand() % 369);
    sp_data->sprite5 = create_sprite(texture, rand() % 799, rand() % 369);
    sp_data->speed = (sfVector2f){12 + rand() % (30 - 12),
        8 + rand() % (15 - 8)};
    sp_data->speed2 = (sfVector2f){12 + rand() % (30 - 12),
        8 + rand() % (15 - 8)};
    sp_data->speed3 = (sfVector2f){12 + rand() % (30 - 12),
        8 + rand() % (15 - 8)};
    sp_data->speed4 = (sfVector2f){12 + rand() % (30 - 12),
        8 + rand() % (15 - 8)};
    sp_data->speed5 = (sfVector2f){12 + rand() % (30 - 12),
        8 + rand() % (15 - 8)};
}

void analyse_events(sfEvent *event, ennemies_t *sp_data, window_t *data,
    game_sprites_t *game_data)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (manage_losing_game(sp_data, &event->mouseButton))
            game_data->clicks_count++;
        else
            game_data->win_count++;
        if (game_data->clicks_count >= 5)
            game_data->lost = 1;
        if (game_data->win_count == 5)
            game_data->win = 1;
        manage_mouse_click(&event->mouseButton, sp_data);
    }
    if (event->type == sfEvtClosed)
        close_window(data->window);
    if (event->type == sfEvtKeyReleased) {
        if (event->key.code == sfKeyR) {
            restart_game(sp_data, data, game_data);
        }
    }
}
