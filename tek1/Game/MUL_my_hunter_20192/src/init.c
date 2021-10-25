/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>

void create_rect(int nb)
{
    sfTexture *texture;
    sfRenderWindow *window;
    sfSprite *sprite;
    sfImage *duc = "src/include/sprite_bird.png";
    sfIntRect rect = {0, 500, 110, 110};

    texture = sfTexture_createFromFile(duc, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);

    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void create_background()
{
    sfRenderWindow    *window;
    sfVideoMode       video_mode = {1920, 1080, 32};
    sfTexture *texture = sfTexture_createFromFile("src/include/background.jpg", NULL);
    sfSprite *sprite;
    sfEvent event;

    window = sfRenderWindow_create(video_mode, "test window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);

    sprite = sfSprite_create();
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