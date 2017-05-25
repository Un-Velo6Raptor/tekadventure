/*
** tuto.c for tuto.c in /home/romain.melin/delivery/Graphics/tekad
** 
** Made by Romain Melin
** Login   <romain.melin@epitech.net>
** 
** Started on  Wed May 24 15:24:31 2017 Romain Melin
** Last update Thu May 25 14:19:19 2017 Romain Melin
*/

# define		SCREEN_WIDTH 1300
# define		SCREEN_HEIGHT 800

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		<SFML/Window/Export.h>
#include		<SFML/Audio.h>
#include		<unistd.h>
#include		"tuto.h"

static sfRenderWindow	*create_window(char *name)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = SCREEN_WIDTH;
  mode.height = SCREEN_HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfClose, NULL);
  if (window == NULL)
    return (NULL);
  sfRenderWindow_setFramerateLimit(window, 1);
  return (window);
}

static void	       	display_window(sfRenderWindow *window, sfTexture **image, sfSprite *sprite)
{
  int			i;

  i = 0;
  sfSprite_setTexture(sprite, image[0], sfTrue);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	{
	  i++;
	  if (i > 7)
	    sfRenderWindow_close(window);
	  sfSprite_setTexture(sprite, image[i], sfTrue);
	  sfRenderWindow_drawSprite(window, sprite, NULL);
	  sfRenderWindow_display(window);
	  my_sleep();
	}
      is_closed(window);
    }
}

static int		the_window(sfRenderWindow *window)
{
  sfTexture		**image;
  sfSprite		*sprite;

  image = load_image();
  if (image == NULL)
    return (84);
  sprite = sfSprite_create();
  if (sprite == NULL)
    {
      free_image(image);
      return (84);
    }
  display_window(window, image, sprite);
  free_image(image);
  return (0);
}

int			tuto()
{
  sfRenderWindow	*window;
  sfMusic		*music;

  window = create_window("SFML Winodw");
  if (window == NULL)
    return (84);
  music = sfMusic_createFromFile
    ("ressources/tuto/Undertale_OST_-_Temmie_Village_Extended.ogg");
  if (music == NULL)
    {
      sfRenderWindow_close(window);
      write(2, "music file is not found\n", 24);
      return (84);
    }
  sfMusic_play(music);
  if (the_window(window) == 84)
    {
      sfMusic_destroy(music);
      write(2, "image file is not found\n", 24);
      return (84);
    }
  sfMusic_destroy(music);
  return (0);
}
