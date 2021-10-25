/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** display_window.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "player.h"
#include "my.h"

void new_window(void)
{
    sfRenderWindow    *window;
    sfVideoMode       video_mode = {1920, 1080, 32};
    sfTexture *texture = sfTexture_createFromFile("src/include/background.jpg", NULL);
    sfImage *texture2 = sfTexture_createFromFile("src/include/sprite_bird.png", NULL);
    sfSprite *sprite;
    sfEvent event;

    window = sfRenderWindow_create(video_mode, "test window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_updateFromImage(texture, texture2, 80, 120);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        // create_rect(0);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}
