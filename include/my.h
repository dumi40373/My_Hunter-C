/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <dirent.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Window.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
typedef struct window {
    sfRenderWindow *window;
    sfSprite *background;
    sfClock *clock;
    sfIntRect rect;
    sfClock *clock2;
    sfTexture *texture2;
} window_t;
typedef struct game_sprite {
    int clicks_count;
    sfSprite *lose_sprite;
    int lost;
    int win_count;
    int win;
    sfSprite *win_sprite;
    sfTexture *texture6;
    sfTexture *texture4;
} game_sprites_t;
typedef struct ennemies {
    sfSprite *sprite;
    sfVector2f speed;
    sfSprite *sprite2;
    sfVector2f speed2;
    sfSprite *sprite3;
    sfVector2f speed3;
    sfSprite *sprite4;
    sfVector2f speed4;
    sfSprite *sprite5;
    sfVector2f speed5;
    int sprite_count;
    sfTexture *texture;
} ennemies_t;
sfRenderWindow *create_window(void);
sfSprite *create_sprite(sfTexture *texture, int x, int y);
sfSprite *create_background(sfTexture *texture);
sfIntRect create_rect(void);
sfTexture *create_texture(void);
sfTexture *create_texture2(void);
void execute_window(void);
void analyse_events(sfEvent *event,
    ennemies_t *sp_data, window_t *data, game_sprites_t *game_data);
void move_sprite(sfRenderWindow *my_window, ennemies_t *sp_data);
void draw_sprites(window_t *data, ennemies_t *sp_data);
void set_sprites_time(window_t *data, ennemies_t *sp_data);
sfTexture *create_texture3(void);
sfSprite *create_game_over(sfTexture *texture);
sfTexture *create_texture4(void);
sfSprite *create_win_game(sfTexture *texture);
int lose_case(game_sprites_t *game_data);
int win_case(game_sprites_t *game_data);
void manage_lose(window_t *data, game_sprites_t *game_data);
void manage_win(window_t *data, game_sprites_t *game_data);
void move_rect(sfIntRect *rect, int offset, int max_value);
void create_hitbox(sfRenderWindow *my_window, sfSprite *sprite,
    sfVector2f *speed);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
void my_new_putstr(char *str);
void destroy(window_t *data, game_sprites_t *game_data, ennemies_t *sp_data);
#endif
