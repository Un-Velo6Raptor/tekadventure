/*
** main.c for main.c in /home/rome157/delivery/Graphics/tekadventure/refresh
** 
** Made by Romain Melin
** Login   <rome157@epitech.net>
** 
** Started on  Mon May 22 14:38:03 2017 Romain Melin
** Last update Tue May 23 17:57:18 2017 Hugo Cousin
*/

# define                SCREEN_WIDTH 600
# define                SCREEN_HEIGHT 400

#include                <stdlib.h>
#include                <SFML/Graphics.h>
#include                <SFML/Window/Export.h>

void                    is_closed(sfRenderWindow *window, sfWindow *relative_to)
{
  sfEvent               event;

  while(sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	{
	  sfRenderWindow_close(window);
	  sfWindow_close(relative_to);
	}
    }
}

void                    the_window(sfRenderWindow *window, sfWindow *relative_to)
{
  sfVector2i            pos_mouse;
  sfTexture		*image;
  sfSprite		*sprite;

  image = sfTexture_createFromFile("magic_mike_tek_ad.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, image, sfTrue);
  sfWindow_setVisible(relative_to, sfFalse);
  while (sfRenderWindow_isOpen(window))
    {
      sfWindow_setPosition(relative_to, sfRenderWindow_getPosition(window));
      sfRenderWindow_clear(window, sfBlack);
      refresh_sprite(sprite, (sfVector2f){0, 0}, 11, 9);
      pos_mouse = sfMouse_getPosition(relative_to);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      is_closed(window, relative_to);
    }
}

sfWindow                *relative_to_window(char *name, int width, int height)
{
  sfVideoMode           mode;
  sfWindow              *relative_to;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  relative_to = sfWindow_create(mode, name, sfClose, NULL);
  if (relative_to == NULL)
    return (NULL);
  return (relative_to);
}

sfRenderWindow          *display_window(char *name, int width, int height)
{
  sfVideoMode           mode;
  sfRenderWindow        *window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfClose, NULL);
  if (window == NULL)
    return (NULL);
  sfRenderWindow_setFramerateLimit(window, 30);
  return (window);
}

int                     main()
{
  sfRenderWindow        *window;
  sfWindow              *relative_to;

  relative_to = relative_to_window("SFML Window", SCREEN_WIDTH, SCREEN_HEIGHT);
  if (relative_to == NULL)
    return (84);
  window = display_window("SFML Window", SCREEN_WIDTH, SCREEN_HEIGHT);
  if (window == NULL)
    return (84);
  the_window(window, relative_to);
  return (0);
}
