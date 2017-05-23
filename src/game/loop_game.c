/*
** loop_game.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 23 17:18:19 2017 Martin Januario
** Last update Tue May 23 17:45:01 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"

static void		check_tmp(sfVector2i to, t_needs *needs, sfVector2i from)
{
  printf("return: %d\n", check_path(&needs->map, from, to));
}

int                     loop_game(t_mode_game *mode, t_needs *needs)
{
  sfEvent               event;

  (void) mode;
  needs->texture = sfTexture_createFromFile("ressources/map/map.png", NULL);
  sfSprite_setTexture(needs->sprite, needs->texture, sfTrue);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, sfBlack);
      while (sfRenderWindow_pollEvent(needs->window, &event))
        {
          if (event.type == sfEvtClosed ||
              sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(needs->window);
	  if (event.type == sfEvtMouseButtonPressed &&
              event.mouseButton.button == sfMouseLeft)
	    check_tmp(vector_2i(event.mouseButton.x, event.mouseButton.y),
		      needs, vector_2i(250, 100));
	}
      sfRenderWindow_drawSprite(needs->window, needs->sprite, NULL);
      sfRenderWindow_display(needs->window);
    }
  sfRenderWindow_destroy(needs->window);
  return (0);
}
