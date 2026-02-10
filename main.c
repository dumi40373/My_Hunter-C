/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** main file
*/

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
#include "lib/my/my.h"
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h")) {
        my_new_putstr("Basic CSFML Project\n");
        my_new_putstr("Duck Hunter features\n");
        my_new_putstr("Goal:\n");
        my_new_putstr("    Shoot the Ducks to win\n");
        my_new_putstr("Options:\n");
        my_new_putstr("    -h: Display this message\n");
        my_new_putstr("    Press R: Restart Game\n");
        my_new_putstr("    Clicks: Maximum of 5 missed hits\n");
        my_new_putstr("    Clicks: Kill 5 ducks to win\n");
        return 0;
    }
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return 84;
    if (argc == 1) {
        srand(time(NULL));
        execute_window();
    }
    return 0;
}
